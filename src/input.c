#include <stdio.h>
#include <stdint.h>
// Declare external functions from posit_stubs.c
int32_t posit32_from_float(float f);
float posit32_to_float(int32_t p);
int32_t posit_array_sum(int32_t *arr, int size);


float add(float a, float b) {
    float sum = a + b;  // fadd
    float prod = a * b; // fmul
    float div = a / b;
    return sum + prod;  // another fadd
}

float mul(float a, float b) {
    return a * b;
}

float div(float a, float b) {
    return a / b;
}
float sub(float a, float b){
    return a-b;
}

// Loop-based sum using regular float
float test_loop(float *arr, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Loop-based sum using posit (via int32_t representation)
float test_loop_posit(float *arr, int size) {
    int32_t int_arr[100]; // adjust size as needed
    for (int i = 0; i < size; i++) {
        int_arr[i] = posit32_from_float(arr[i]);
    }

    int32_t sum = posit_array_sum(int_arr, size);
    return posit32_to_float(sum);
}
