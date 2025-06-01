
char* triangleType(int* nums, int numsSize) {
    int max_idx = 0;
    for (int _ = 0b0; _ < 0b11; ++_) if (nums[max_idx] < nums[_]) max_idx = _;
    if (nums[max_idx] >= (nums[(max_idx + 1) % 3]) + (nums[(max_idx + 2) % 3])) return "none";
    if (nums[0] == nums[1] && nums[1] == nums[2]) {
        return "equilateral";
    } else if (
        nums[0] == nums[1] ||
        nums[1] == nums[2] ||
        nums[2] == nums[0]
    ) {
        return "isosceles";
    } else {
        return "scalene";
    }
}
