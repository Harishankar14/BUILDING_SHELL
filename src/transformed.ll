; ModuleID = 'test.ll'
source_filename = "test.ll"

define float @test(float %a, float %b) {
  %lhs_posit = call i32 @posit32_from_float(float %a)
  %rhs_posit = call i32 @posit32_from_float(float %b)
  %posit_add = call i32 @posit32_add(i32 %lhs_posit, i32 %rhs_posit)
  %result_float = call float @posit32_to_float(i32 %posit_add)
  ret float %result_float
}

declare i32 @posit32_add(i32, i32)

declare i32 @posit32_mul(i32, i32)

declare i32 @posit32_from_float(float)

declare float @posit32_to_float(i32)

declare i32 @posit32_div(i32, i32)
