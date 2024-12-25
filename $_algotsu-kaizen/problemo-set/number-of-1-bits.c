// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

int hammingWeight(int n) {
    int count = 0b0, guinea_pig = n, bit = 0b1; 
    do guinea_pig & bit && ++count; while (guinea_pig = guinea_pig >> bit);
    return count;
}
