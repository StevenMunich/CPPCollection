#include <stdio.h>
#include <time.h>

#define VALIDATE_RANGE(x, min, max) ((x) >= (min) && (x) <= (max))

int validate_range(int x, int min, int max) {
    if (x < min) return 0;
    if (x > max) return 0;
    return 1;
}

int main() {
    const int min = 0;
    const int max = 100;
    int x = 42;
    int iterations = 1000078908870000;
    int result;

    clock_t start, end;

    // Macro timing
    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = VALIDATE_RANGE(x, min, max);
    }
    end = clock();
    printf("Macro time: %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Function timing
    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = validate_range(x, min, max);
    }
    end = clock();
    printf("Function time: %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
