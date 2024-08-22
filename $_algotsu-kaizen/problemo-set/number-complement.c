#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int findComplement(int num) {
    unsigned int bit = 0b1;
    int U_INT_0x20 = num;

    while (bit <= U_INT_0x20) {
        if (U_INT_0x20 & bit)
            U_INT_0x20 ^= bit;
        else
            U_INT_0x20 |= bit;
        bit = bit << 0b1;
    }

    return U_INT_0x20;
}

int main()
{
    printf("OUT [%d] == 2\n", findComplement(5));
    printf("OUT [%d] == 0\n", findComplement(1));
    printf("OUT [%d] == 0\n", findComplement(2147483647));

    return 0;
}
