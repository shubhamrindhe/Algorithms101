#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int *bills, int billsSize)
{
    int fives = 0b0, tens = 0b0;
    for (int i = 0; i < billsSize; ++i)
    {
        switch (*(bills + i))
        {
        case 0x5:
            ++fives;
            break;
        case 0xA:
            if (fives <= 0x0)
                return false;
            --fives;
            ++tens;
            break;
        case 0x14:
            if (tens > 0x0 && fives > 0x0)
            {
                --tens;
                --fives;
                break;
            }
            else if (fives >= 0x3)
            {
                fives -= 0x3;
                break;
            }

            return false;
        }
    }

    return true;
}

int main()
{
    // Input: bills = [5,5,5,10,20]
    // Output: true
    int in1[] = {5, 5, 5, 10, 20};
    printf("OUT [%d] == TRUE\n", lemonadeChange(in1, 6));

    // Input: bills = [5,5,10,10,20]
    // Output: false
    int in2[] = {5, 5, 10, 10, 20};
    printf("OUT [%d] == FALSE\n", lemonadeChange(in2, 6));

    // Input: bills = [5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5]
    // Output: true
    int in3[] = {5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};
     printf("OUT [%d] == TRUE\n", lemonadeChange(in3, 20));

    return 0;
}
