int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// int find_first(int *array, int size, int val) {
//     int l =
// }

int triangleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int result =0;
    for (int i = numsSize - 0x1; i >= 0x0; --i) {
        // printf(" %d ", nums[i]);
        int l = 0, r = i - 1;
        while (l < r)
            if (nums[l] + nums[r] > nums[i]) result += (r--) - l;
            else l++;
    }

    return result;
}
