#include <stdio.h>
#include <stdlib.h>  // for atof
//extern float test_loop(float *arr, int size);
extern float test_loop_posit(float *arr, int size);
extern float mul(float a, float b);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s num1 num2 num3 ...\n", argv[0]);
        return 1;
    }

    int size = argc - 1;
    float arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = atof(argv[i + 1]);  // convert strings to floats
    }

    //float float_result = test_loop(arr, size);
    float posit_result = test_loop_posit(arr, size);

    printf("Float sum: %.2f\n", float_result);
    printf("Posit (stub) sum: %.2f\n", posit_result);

    return 0;
}
