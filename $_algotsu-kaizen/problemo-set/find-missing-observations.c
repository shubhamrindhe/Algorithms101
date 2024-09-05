#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int* missingRolls(int* rolls, int m, int mean, int n, int* returnSize) {
    long sigma = mean * (m + n);
    long partialSum = 0b0;
    for (int i = 0; i < m; ++i) partialSum += *(rolls + i);
    long kai = sigma - partialSum;
    *returnSize = 0x0;
    if (kai > n * 0b110 || kai < n) return NULL;

    *returnSize = n;
    int avg = kai / n;
    int r = kai % n;
    int *missing = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) *(missing + i) = avg;
    for (int i = 0; i < r; ++i) *(missing + i) += 0b1;
    return missing;
}

// int main()
// {
//     printf("OUT [%d] == 2\n", nearestPalindromic("5"));
//     printf("OUT [%d] == 0\n", nearestPalindromic("1"));
//     printf("OUT [%d] == 0\n", nearestPalindromic("2147483647"));

//     return 0;
// }
