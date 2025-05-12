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

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local float @mul(float noundef %0, float noundef %1) #0 {
  %3 = alloca float, align 4
  %4 = alloca float, align 4
  %5 = alloca float, align 4
  store float %0, ptr %3, align 4
  store float %1, ptr %4, align 4
  %6 = load float, ptr %3, align 4
  %7 = load float, ptr %4, align 4
  %8 = fmul float %6, %7
  store float %8, ptr %5, align 4
  %9 = load float, ptr %5, align 4
  ret float %9
}

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local float @div(float noundef %0, float noundef %1) #0 {
  %3 = alloca float, align 4
  %4 = alloca float, align 4
  %5 = alloca float, align 4
  store float %0, ptr %3, align 4
  store float %1, ptr %4, align 4
  %6 = load float, ptr %3, align 4
  %7 = load float, ptr %4, align 4
  %8 = fdiv float %6, %7
  store float %8, ptr %5, align 4
  %9 = load float, ptr %5, align 4
  ret float %9
}

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local float @test_loop(ptr noundef %0, i32 noundef %1) #0 {
  %3 = alloca ptr, align 8
  %4 = alloca i32, align 4
  %5 = alloca float, align 4
  %6 = alloca i32, align 4
  store ptr %0, ptr %3, align 8
  store i32 %1, ptr %4, align 4
  store float 0.000000e+00, ptr %5, align 4
  store i32 0, ptr %6, align 4
  br label %7

7:                                                ; preds = %19, %2
  %8 = load i32, ptr %6, align 4
  %9 = load i32, ptr %4, align 4
  %10 = icmp slt i32 %8, %9
  br i1 %10, label %11, label %22

11:                                               ; preds = %7
  %12 = load ptr, ptr %3, align 8
  %13 = load i32, ptr %6, align 4
  %14 = sext i32 %13 to i64
  %15 = getelementptr inbounds float, ptr %12, i64 %14
  %16 = load float, ptr %15, align 4
  %17 = load float, ptr %5, align 4
  %18 = fadd float %17, %16
  store float %18, ptr %5, align 4
  br label %19

19:                                               ; preds = %11
  %20 = load i32, ptr %6, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, ptr %6, align 4
  br label %7, !llvm.loop !6

22:                                               ; preds = %7
  %23 = load float, ptr %5, align 4
  ret float %23
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
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
