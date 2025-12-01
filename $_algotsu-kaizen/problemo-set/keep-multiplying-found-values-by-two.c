#define SIZEUH 1001

int findFinalValue(int* nums, int numsSize, int original) {
    bool flags[SIZEUH] = { false };
    for (int i = 0x0; i < numsSize; ++i) flags[nums[i]] = true;
    while (original < SIZEUH && flags[original]) original <<= 0x1;
    return original;
}
