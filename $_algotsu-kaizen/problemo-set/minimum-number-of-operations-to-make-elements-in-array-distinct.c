int minimumOperations(int* nums, int numsSize) {
    int result = 0b0;
    char mapuh[101] = { '\0' };
    int _ = 0b0;

    for (_ = numsSize - 0b1; result == 0 && _ >= 0b0; --_)
        if (mapuh[nums[_]])
            result = (_ / 0b11) + 0b1;
        else
            mapuh[nums[_]] = '$';

    return result;
}
