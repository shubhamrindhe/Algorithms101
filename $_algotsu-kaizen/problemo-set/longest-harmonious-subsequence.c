
int compare_asc(const void *a, const void *b) {
    return *((int*)a) - *((int*)b);
}

int findLHS(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare_asc);
    for (int i = 0; i < numsSize; ++i) printf(" (%d, %d) ", i, nums[i]);

    register int result = 0x0, f_minus_one = 0x0, one = nums[0x0], f_one = 0x1, i;
    for (i = 0x1; i < numsSize; ++i) {
        if (nums[i] == one && ++f_one) continue;
        // printf("\n(%d, %d) ", f_one, f_minus_one);

        if (f_minus_one > 0 && f_one > 0 && result < (f_one + f_minus_one)) {
            result = f_one + f_minus_one;
        }

        f_minus_one = nums[i] - one == 1 ? f_one : 0;
        one = nums[i];
        f_one = 0x1;
    }

    if (f_minus_one > 0 && f_one > 0 && result < (f_one + f_minus_one)) {
        result = f_one + f_minus_one;
    }

    return result;
}
