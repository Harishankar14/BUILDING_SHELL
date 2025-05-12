; ModuleID = 'input.c'
source_filename = "input.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local float @add(float noundef %0, float noundef %1) #0 {
  %3 = alloca float, align 4
  %4 = alloca float, align 4
  %5 = alloca float, align 4
  %6 = alloca float, align 4
  %7 = alloca float, align 4
  store float %0, ptr %3, align 4
  store float %1, ptr %4, align 4
  %8 = load float, ptr %3, align 4
  %9 = load float, ptr %4, align 4
  %10 = fadd float %8, %9
  store float %10, ptr %5, align 4
  %11 = load float, ptr %3, align 4
  %12 = load float, ptr %4, align 4
  %13 = fmul float %11, %12
  store float %13, ptr %6, align 4
  %14 = load float, ptr %3, align 4
  %15 = load float, ptr %4, align 4
  %16 = fdiv float %14, %15
  store float %16, ptr %7, align 4
  %17 = load float, ptr %5, align 4
  %18 = load float, ptr %6, align 4
  %19 = fadd float %17, %18
  ret float %19
}

attributes #0 = { noinline nounwind optnone sspstrong uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 19.1.7"}
