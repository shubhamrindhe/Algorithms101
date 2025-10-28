int search(int* arr, int size, int x) {
    int l = 0x0, r = size;

    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] > x) r = m;
        else l = m + 1;
    }

    return l < size ? l : -1;
}

int countPairs(int* nums, int numsSize, int target) {
    int result = 0x0;

    for (int i = 0x0; i < numsSize - 1; ++i)
        for (int j = i + 0x1; j < numsSize; ++j)
            if (nums[i] + nums[j] < target) ++result;

    return result;
}
