#include "llvm/IR/PassManager.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

struct PositPass : public PassInfoMixin<PositPass> {
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
    Module *M = F.getParent();
    bool Modified = false;

    Type *Posit32Ty = Type::getInt32Ty(M->getContext());
    Type *FloatTy = Type::getFloatTy(M->getContext());

    // Define library functions
    FunctionCallee PositAdd = M->getOrInsertFunction("posit32_add", Posit32Ty, Posit32Ty, Posit32Ty);
    FunctionCallee PositMul = M->getOrInsertFunction("posit32_mul", Posit32Ty, Posit32Ty, Posit32Ty);
    FunctionCallee PositFromFloat = M->getOrInsertFunction("posit32_from_float", Posit32Ty, FloatTy);
    FunctionCallee PositToFloat = M->getOrInsertFunction("posit32_to_float", FloatTy, Posit32Ty);
    FunctionCallee PositDiv=M->getOrInsertFunction("posit32_div",Posit32Ty,Posit32Ty,Posit32Ty);
    FunctionCalle PositSub=M->getOrInsertFunction("posit32_sub",Posit32Ty,Posit32Ty,Posit32Ty);

    for (BasicBlock &BB : F) {
      SmallVector<Instruction *, 8> ToReplace;
      for (Instruction &I : BB) {
        if (I.getType()->isFloatTy()) {
          if (I.getOpcode() == Instruction::FAdd || I.getOpcode() == Instruction::FMul || I.getOpcode() == Instruction::FDiv || I.getOpcode() == Instruction::FSub) {
            ToReplace.push_back(&I);
          }
        }
      }
      for (Instruction *I : ToReplace) {
        IRBuilder<> Builder(I);
        Value *LHS = I->getOperand(0);
        Value *RHS = I->getOperand(1);

        // Convert float operands to posit32_t
        Value *LHSPosit = Builder.CreateCall(PositFromFloat, {LHS}, "lhs_posit");
        Value *RHSPosit = Builder.CreateCall(PositFromFloat, {RHS}, "rhs_posit");

        Value *ResultPosit;
        if (I->getOpcode() == Instruction::FAdd) {
          ResultPosit = Builder.CreateCall(PositAdd, {LHSPosit, RHSPosit}, "posit_add");
        } else if(I->getOpcode() == Instruction::FMul) { // FMul
          ResultPosit = Builder.CreateCall(PositMul, {LHSPosit, RHSPosit}, "posit_mul");
        }else if(I->getOpcode() == Instruction::FDiv){
          ResultPosit=Builder. CreateCall(PositDiv,{LHSPosit,RHSPosit},"posit_div");
        }else{
          ResultPosit=Builder.CreateCall(PositSub,{LHSPosit,RHSPosit},"posit_sub");
        }
        Value *ResultFloat = Builder.CreateCall(PositToFloat, {ResultPosit}, "result_float");

        I->replaceAllUsesWith(ResultFloat);
        I->eraseFromParent();
        Modified = true;
      }
    }
    return Modified ? PreservedAnalyses::none() : PreservedAnalyses::all();
  }
  static bool isRequired() { return true; }
};

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "PositPass", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "positpass") {
                    FPM.addPass(PositPass());
                    return true;
                  }
                  return false;
                });
            PB.registerOptimizerLastEPCallback(
                [](ModulePassManager &MPM, OptimizationLevel) {
                  MPM.addPass(createModuleToFunctionPassAdaptor(PositPass()));
                });
          }};
}