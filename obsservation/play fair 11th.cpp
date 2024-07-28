#include <stdio.h>
#include <math.h>

int main() {
    // Calculate 25!
    double log25Factorial = 0;
    for (int i = 1; i <= 25; i++) {
        log25Factorial += log2(i);
    }

    // Calculate (5!)^2
    double log5Factorial = 0;
    for (int i = 1; i <= 5; i++) {
        log5Factorial += log2(i);
    }
    double log5FactorialSquared = 2 * log5Factorial;

    // Number of possible keys
    double possibleKeys = log25Factorial;
    // Number of effectively unique keys
    double uniqueKeys = log25Factorial - log5FactorialSquared;

    // Print the results
    printf("Number of possible keys (approx): 2^%.1f\n", possibleKeys);
    printf("Number of effectively unique keys (approx): 2^%.1f\n", uniqueKeys);

    return 0;
}
