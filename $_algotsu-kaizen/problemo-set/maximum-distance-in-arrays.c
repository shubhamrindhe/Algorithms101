#include <stdio.h>
#include <limits.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int maxDistance(int **arrays, int arraysSize, int *arraysColSize)
{
    int min = INT_MIN, max = INT_MAX, kai = 0;
    for (int i = 0; i < arraysSize; ++i)
    {
        int localMin = *(*(arrays + i));
        int localMax = *(*(arrays + i) + *(arraysColSize + i) - 1);
        kai = MAX(kai, MAX(localMax - min, max - localMin));
        min = MIN(min, localMin);
        max = MAX(max, localMax);
    }

    return kai;
}

int main()
{
    // Input: arrays = [[1,2,3],[4,5],[1,2,3]]
    // Output: 4
    int in1[3][] = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    int s1[] = {3, 2, 3};
    printf("OUT [%d] == FALSE\n", maxDistance(in1, 3, s1));

    // Input: arrays = [[1],[1]]
    // Output: 0
    int in2[3][] = {{1}, {1}};
    int s2[] = {1, 1};
    printf("OUT [%d] == FALSE\n", maxDistance(in2, 2, s2));

    // Input: arrays = [[1,5],[3,4]]
    // Output: 0
    int in3[3][] = {{1, 5}, {3, 4}};
    int s3[] = {2, 2};
    printf("OUT [%d] == TRUE\n", maxDistance(in3, 2, s3));

    return 0;
}
