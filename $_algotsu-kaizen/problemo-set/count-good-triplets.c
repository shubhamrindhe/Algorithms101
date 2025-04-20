
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
    int result = 0b0;

    // for (int i = 0; i < arrSize; ++i)
    //     for (int j = i + 1; j < arrSize; ++j)
    //         for (int k = j + 1; k < arrSize; ++k)
    //             abs(arr[i] - arr[j]) <= a &&
    //             abs(arr[j] - arr[k]) <= b &&
    //             abs(arr[i] - arr[k]) <= c &&
    //             ++result;

    for (int i = 0; i < arrSize; ++i)
        for (int j = i + 1; j < arrSize; ++j) {
            if (abs(arr[i] - arr[j]) > a) continue;
            for (int k = j + 1; k < arrSize; ++k)
                abs(arr[j] - arr[k]) <= b &&
                abs(arr[i] - arr[k]) <= c &&
                ++result;
        }

    return result;
}
