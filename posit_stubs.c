#include <stdint.h>
extern int32_t posit32_from_float(float f);
extern int32_t posit_array_sum(int32_t *arr, int size);
extern float posit32_to_float(int32_t p);
// Stubbed posit addition using float under the hood
int32_t posit32_add(int32_t a, int32_t b) {
    float fa = *(float *)&a;
    float fb = *(float *)&b;
    float result = fa + fb;
    return *(int32_t *)&result;
}

// Stubbed posit multiplication
int32_t posit32_mul(int32_t a, int32_t b) {
    float fa = *(float *)&a;
    float fb = *(float *)&b;
    float result = fa * fb;
    return *(int32_t *)&result;
}

// Stubbed posit division
int32_t posit32_div(int32_t a, int32_t b) {
    float fa = *(float *)&a;
    float fb = *(float *)&b;
    float result = fa / fb;
    return *(int32_t *)&result;
}

int32_t posit32_sub(int32_t a, int32_t b){
    float fa=*(float *)&a;
    float fb=*(float *)&b;
    float result=fa-fb;
    return *(int32_t *)&result;
}

float test_loop_posit(float *arr, int size) {
    int32_t posit_arr[size];
    for (int i = 0; i < size; i++) {
        posit_arr[i] = posit32_from_float(arr[i]);
    }

    int32_t sum_posit = posit_array_sum(posit_arr, size);
    return posit32_to_float(sum_posit);
}

// float test_loop(float *arr, int size){
//     int32_t posit_arr[size];
//     for(int i=0;i<size;i++){
//         posit_arr[i]=
//     }
// }
// Convert float to posit (int32_t representation)
int32_t posit32_from_float(float f) {
    return *(int32_t *)&f;
}

// Convert posit (int32_t representation) to float
float posit32_to_float(int32_t p) {
    return *(float *)&p;
}

// Posit array summation using posit32_add
int32_t posit_array_sum(int32_t *arr, int size) {
    int32_t sum = 0;
    for (int i = 0; i < size; i++) {
        sum = posit32_add(sum, arr[i]);
    }
    return sum;
}
