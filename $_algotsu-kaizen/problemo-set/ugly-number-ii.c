#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MIN3(X, Y, Z) ((X) < (Y) ? ((X) < (Z) ? (X) : (Z)) : ((Y) < (Z) ? (Y) : (Z)))

int nthUglyNumber(int n) {
    int *ugly_list = (int *)malloc(n * sizeof(int));
    *ugly_list = 0x1;
    int size = 0x1, next = 0x1, idx2 = 0b0, idx3 = 0b0, idx5 = 0b0;

    for (int i = 0b1; i < n; ++i) {
        int m2 = *(ugly_list + idx2) * 0b010;
        int m3 = *(ugly_list + idx3) * 0b011;
        int m5 = *(ugly_list + idx5) * 0b101;

        next = MIN3(m2, m3, m5);
        *(ugly_list + i) = next;

        // printf("\n");
        // printf("\n m2 = %d, m3 = %d, m5 = %d ::: MIN : %d ", m2, m3, m5, next);
        // printf("\n");

        // if (next == m2) ++idx2;
        // if (next == m3) ++idx3;
        // if (next == m5) ++idx5;
        next == m2 && ++idx2;
        next == m3 && ++idx3;
        next == m5 && ++idx5;
    }

    free(ugly_list);

    return next;
}

int main()
{
    printf("OUT [%d] == 12\n", nthUglyNumber(10));
    printf("OUT [%d] == 1\n", nthUglyNumber(1));

    return 0;
}
