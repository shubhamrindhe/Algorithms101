
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int a_mask = 0b00001;
        int e_mask = 0b00010;
        int i_mask = 0b00100;
        int o_mask = 0b01000;
        int u_mask = 0b10000;

        int max_len = 0b0, idx = 0b0, state = 0b0;
        vector<int> bits(0x20, -0b10);
        bits[0b0] = -0b1;

        for (char c : s) {
            switch (c) {
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
                max_len = std::max(max_len, idx - xidx);

            idx++;
        }

        return max_len;
    }
};
