#define LIMIT 501
#define BYTE_S 0b1000

typedef enum {
  SET,
  UNSET
} TOGGLE_RESULT;

char* new_bitflags(int n) {
    return (char *)calloc(sizeof(char), (n / BYTE_S) + 0b1);
}

TOGGLE_RESULT toggle_flag(char *bit_flags, int idx) {
    int byte_idx = idx / BYTE_S;
    int bit_idx = idx % BYTE_S;
    char MASK = 0b1 << bit_idx;
    bit_flags[byte_idx] ^= MASK;
    return (bit_flags[byte_idx] & MASK) ? SET : UNSET;
}

// bool get_flag(char *bit_flags, int idx) {
//     int byte_idx = idx / BYTE_S;
//     int bit_idx = idx % BYTE_S;
//     return bit_flags[byte_idx] & (0b1 << bit_idx);
// }

bool divideArray(int* nums, int numsSize) {
    // char parity_list[LIMIT] = { '\0' };
    // for (int i = 0; i < numsSize; ++i) parity_list[nums[i]] ^= '$';
    // for (int i = 0; i < LIMIT; ++i) if (parity_list[i]) return false;
    // return true;
    char* parity_flag_buffer = new_bitflags(LIMIT);
    for (int i = 0; i < numsSize; ++i) toggle_flag(parity_flag_buffer, nums[i]);
    for (int i = 0; i < (LIMIT / BYTE_S) + 0b1; ++i) if (parity_flag_buffer[i]) return false;
    return true;
}
