#define DASHAM 0b1010
#define SHUNYA 0b0
#define EKAM 0b1

int setDigitAt(int number, int index, int digit) {
    int x = pow(DASHAM, index);
    return (((number / (x * DASHAM)) * DASHAM + digit) * x) + (number % x);
}

int maximumSwap(int num) {
    int guinea_pig = num;
    int idx = SHUNYA, max = SHUNYA, min = SHUNYA, max_idx = SHUNYA, min_idx = SHUNYA;
    int swap_idx_min = -EKAM, swap_idx_max = -EKAM;
    int swap_digit_min = -EKAM, swap_digit_max = -EKAM;
    while (guinea_pig) {
        int digit = guinea_pig % DASHAM;
        if (digit > max) {
            max_idx = idx;
            max = digit;
        } else if (digit < max && max > SHUNYA) {
            min_idx = idx;
            min = digit;
            swap_idx_min = min_idx;
            swap_idx_max = max_idx;
            swap_digit_min = min;
            swap_digit_max = max;
        }
        guinea_pig /= DASHAM;
        ++idx;
    }

    if (swap_idx_min <= swap_idx_max) return num;

    // int max_swpped_with_min = setDigitAt(num, swap_idx_max, swap_digit_min);
    // int min_swpped_with_max = setDigitAt(max_swpped_with_min, swap_idx_min, swap_digit_max);
    // return min_swpped_with_max;

    return setDigitAt(
        setDigitAt(
            num,
            swap_idx_max, 
            swap_digit_min
        ), 
        swap_idx_min, 
        swap_digit_max);

    // int x = pow(DASHAM, swap_idx_max);
    // int y = pow(DASHAM, swap_idx_min);

    // int max_swpped_with_min = (((num / (x * DASHAM)) * DASHAM + swap_digit_min) * x) + (num % x);
    // return (((max_swpped_with_min / (y * DASHAM)) * DASHAM + swap_digit_max) * y) + (max_swpped_with_min % y);
}
