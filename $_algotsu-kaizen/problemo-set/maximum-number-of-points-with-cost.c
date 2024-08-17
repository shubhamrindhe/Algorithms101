#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define SHUNYAFY(ptr, size) memset(ptr, 0, size)

#define FIND_MAX(array, size) ({     \
    typeof(array[0]) max = array[0]; \
    for (int i = 1; i < size; i++)   \
    {                                \
        if (array[i] > max)          \
        {                            \
            max = array[i];          \
        }                            \
    }                                \
    max;                             \
})

int **box_2_ptr_d2(int rows, int columns, int arr[rows][columns])
{
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
        array[r] = (int *)malloc(columns * sizeof(int));

    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < columns; ++c)
            array[r][c] = arr[r][c];

    return array;
}

int main()
{

    // [
    //     [1, 2, 3],
    //     [1, 5, 1],
    //     [3, 1, 1],
    //   ],
    //   9
    int in1[3][3] = {
        {1, 2, 3},
        {1, 5, 1},
        {3, 1, 1},
    };
    int in1_ = 3;
    // printf("OUT [%d] == 9\n", maxPoints((int **)box_2_ptr_d2(3, 3, in1), 3, &in1_));

    // [
    // [1, 5],
    // [2, 3],
    // [4, 2],
    //   ],
    //   11
    int in2[3][3] = {
        {1, 5},
        {2, 3},
        {4, 2},
    };
    int in2_ = 2;
    printf("OUT [%d] == 11\n", maxPoints((int **)box_2_ptr_d2(3, 2, in2), 3, &in2_));

    // [ [3], [4], [2], [0] ], 9

    int in3[3][3] = {
        {3}, {4}, {2}, {0}};
    int in3_ = 1;
    printf("OUT [%d] == 9\n", maxPoints((int **)box_2_ptr_d2(3, 1, in3), 4, &in3_));

    //                             [
    // [ 5, 2, 1, 2 ],
    // [ 2, 1, 5, 2 ],
    // [ 5, 5, 5, 0 ],
    // ] 13

    int in4[3][4] = {
        {5, 2, 1, 2},
        {2, 1, 5, 2},
        {5, 5, 5, 0},
    };
    int in4_ = 4;
    printf("OUT [%d] == 13\n", maxPoints((int **)box_2_ptr_d2(3, 4, in4), 3, &in4_));

    return 0;
}
