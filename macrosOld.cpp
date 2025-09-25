#include <stdio.h>
#include <stdlib.h>

// Input Validation Macro
#define VALIDATE_RANGE(val, min, max) \
    ((val) >= (min) && (val) <= (max))

// Division Guardrail Macro
#define IS_DIV_SAFE(b) \
    ((b) != 0)

// Array Access Macro
#define IS_ARRAY_ACCESS_SAFE(arr, size, index) \
    ((arr) != NULL && (index) >= 0 && (index) < (size))

int main() {
    int input = 105;
    int a = 10, b = 0, result = 0;
    int data[] = {1, 2, 3, 4, 5};
    int error_flag = 0;

    printf("=== Runtime Checker (No goto) ===\n");

    // Input validation
    if (!VALIDATE_RANGE(input, 0, 100)) {
        printf("[Runtime Check] Invalid input: %d (Expected: 0–100)\n", input);
        error_flag = 1;
    }

    // Division guardrail
    if (!IS_DIV_SAFE(b)) {
        printf("[Runtime Check] Division by zero\n");
        error_flag = 1;
    } else {
        result = a / b;
        printf("? Division result: %d\n", result);
    }

    // Array access
    int index = 7;
    if (!IS_ARRAY_ACCESS_SAFE(data, 5, index)) {
        printf("[Runtime Check] Array index out of bounds or null pointer: %d\n", index);
        error_flag = 1;
    } else {
        printf("Array[%d] = %d\n", index, data[index]);
    }

    // Final status
    if (error_flag) {
        printf(" Execution completed with runtime violations\n");
        return 1;
    } else {
        printf(" All runtime checks passed\n");
        return 0;
    }
}
