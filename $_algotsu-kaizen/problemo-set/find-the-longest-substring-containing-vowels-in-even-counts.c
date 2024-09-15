
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int a_mask = 0b00001;
int e_mask = 0b00010;
int i_mask = 0b00100;
int o_mask = 0b01000;
int u_mask = 0b10000;

int findTheLongestSubstring(char* string) {
    int max_len = 0b0, idx = 0b0, state = 0b0;
    int bits[0x20] = { 0 };
    for (int i = 0; i < 0x20 ;++i) *(bits + i) = -0b10;
    bits[0b0] = -0b1;
    char _ = '\0';

    while (_ = *(string + idx)) {
        switch (_) {
            case 'a':
                state ^= a_mask;
                break;
            case 'e':
                state ^= e_mask;
                break;
            case 'i':
                state ^= i_mask;
                break;
            case 'o':
                state ^= o_mask;
                break;
            case 'u':
                state ^= u_mask;
                break;
        }

        int xidx = bits[state];
        if (xidx == -0b10)
            bits[state] = idx;
        else
            max_len = MAX(max_len, idx - xidx);
        idx++;
    }

    return max_len;
}
