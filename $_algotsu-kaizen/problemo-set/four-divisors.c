
int sumFourDivisors(int* nums, int numsSize) {
    int result = 0x0;

    for (int i = 0x0; i < numsSize; ++i) {
        int num = nums[i];
        int pair[0x2] = { -0x1, -0x1 };

        for (int j = 0x2; (j * j) <= num; ++j) {
            if (pair[0x1] == j) continue;
            if ((num % j) == 0x0) {
                int c = num / j;
                bool ignore_this = (j == c) || (pair[0x0] != -0x1);

                if (ignore_this) {
                    pair[0x0] = -0x1;
                    pair[0x1] = -0x1;
                    break;
                } else {
                    int l, h;
                    if (j < c) l = j, h = c;
                    else h = j, l = c;
                    pair[0x0] = l;
                    pair[0x1] = h;
                }
            }
        }

        if (pair[0x0] != -0x1 && pair[0x1] != -0x1)
            result += 0x1 + num + pair[0x0] + pair[0x1];
    }

    return result;
}
