
int countOdds(int low, int high){
    return ((high + 0x1) >> 0x1) - ((low) >> 0x1);
}

// 0 1 2 3 4 5 6
// [L] [H]
//  0   0  = l - 2
//  0   1  = l - 1
//  1   0  = l - 1
//  1   1  = l +
