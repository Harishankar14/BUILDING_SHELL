; ModuleID = 'posit_stubs.c'
source_filename = "posit_stubs.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local i32 @posit32_from_float(float noundef %0) #0 {
  %2 = alloca float, align 4
  store float %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  ret i32 %3
}

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local float @posit32_to_float(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load float, ptr %2, align 4
  ret float %3
}

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local i32 @posit32_add(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca float, align 4
  %6 = alloca float, align 4
  %7 = alloca float, align 4
  store i32 %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  %8 = load float, ptr %3, align 4
  store float %8, ptr %5, align 4
  %9 = load float, ptr %4, align 4
  store float %9, ptr %6, align 4
  %10 = load float, ptr %5, align 4
  %11 = load float, ptr %6, align 4
  %12 = fadd float %10, %11
  store float %12, ptr %7, align 4
  %13 = load i32, ptr %7, align 4
  ret i32 %13
}

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local i32 @posit32_mul(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca float, align 4
  %6 = alloca float, align 4
  %7 = alloca float, align 4
  store i32 %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  %8 = load float, ptr %3, align 4
  store float %8, ptr %5, align 4
  %9 = load float, ptr %4, align 4
  store float %9, ptr %6, align 4
  %10 = load float, ptr %5, align 4
  %11 = load float, ptr %6, align 4
  %12 = fmul float %10, %11
  store float %12, ptr %7, align 4
  %13 = load i32, ptr %7, align 4
  ret i32 %13
}

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local i32 @posit32_div(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca float, align 4
  %6 = alloca float, align 4
  %7 = alloca float, align 4
  store i32 %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  %8 = load float, ptr %3, align 4
  store float %8, ptr %5, align 4
  %9 = load float, ptr %4, align 4
  store float %9, ptr %6, align 4
  %10 = load float, ptr %5, align 4
  %11 = load float, ptr %6, align 4
  %12 = fdiv float %10, %11
  store float %12, ptr %7, align 4
  %13 = load i32, ptr %7, align 4
  ret i32 %13
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
