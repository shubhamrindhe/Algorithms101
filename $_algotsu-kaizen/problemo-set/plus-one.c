
void reverse(int arr[], int size) {
    int l = 0, r = size - 1;
    while (l < r) {
        int lv = arr[l];
        arr[l] = arr[r];
        arr[r] = lv;
        ++l;
        --r;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * (digitsSize + 1));
    *returnSize = digitsSize;

    int carry = 0x1, sum;
    for (int l = 0x0, r = digitsSize - 0x1; r >= 0x0; --r, ++l) {
        sum = digits[r] + carry;
        result[l] = sum % 0xA;
        carry = sum / 0xA;
    }

    if (carry > 0x0) result[(*returnSize)++] = carry;
    reverse(result, *returnSize);

    return result;
}
