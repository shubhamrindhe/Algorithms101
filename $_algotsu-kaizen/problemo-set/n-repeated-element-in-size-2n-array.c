#define MAX_VALUE 10001
#define MAX_SIZE ((MAX_VALUE / 8) + 1)

int repeatedNTimes(int* nums, int numsSize) {
    uint8_t flags[MAX_SIZE];
    memset(flags, 0x0, sizeof(flags));

    for (int i = 0x0; i < numsSize; ++i) {
        int byte_idx = nums[i] / 0x8;
        int bit_idx = nums[i] % 0x8;
        uint8_t mask = (uint8_t)(1u << bit_idx);
        if (flags[byte_idx] & mask) return nums[i];
        else flags[byte_idx] |= mask;
    }

    return -0x1;
}
