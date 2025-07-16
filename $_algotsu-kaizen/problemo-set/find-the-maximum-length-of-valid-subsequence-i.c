#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int maximumLength(int* nums, int numsSize) {
    int register i = 0x0;
    int parities[] = { 0x0, 0x0 }, alternate = 0x1;
    bool parity_minus_one = nums[0x0] & true, parity;

    for (i = 0x0; i < numsSize; ++i) {
        ++parities[(parity = nums[i] & true)];
        if (i && parity != parity_minus_one && ++alternate) parity_minus_one = parity;
    }

    return MAX(MAX(parities[false], parities[true]), alternate);
}
