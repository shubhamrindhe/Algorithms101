#include <inttypes.h>
#include <stdint.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int* result = (int *)malloc(sizeof(int) * ASize);
    *returnSize = ASize;
    // bool* _A_ = (bool *)calloc(sizeof(bool), ASize + 1);
    // bool* _B_ = (bool *)calloc(sizeof(bool), ASize + 1);
    // int count = 0;
    // for (int i = 0; i < ASize; ++i) {
    //     _A_[A[i]] = true;
    //     _B_[B[i]] = true;
    //     _A_[B[i]] && _B_[A[i]] && ++count;

    //     // _A_[B[i]] && ++count;
    //     // _B_[A[i]] && ++count;
    //     result[i] = count;
    // }
    // free(_A_);
    // free(_B_);

    uint64_t _A_ = 0b0LL;
    uint64_t _B_ = 0b0LL;
    for(int i = 0; i < ASize; i++){
        // _A_ |= 0b1LL << A[i];
        // _B_ |= 0b1LL << B[i];
        // uint64_t _ = _A_ & _B_;
        uint64_t _ = (_A_ |= 0b1LL << A[i]) & (_B_ |= 0b1LL << B[i]);
        int f1 = 0b0;
        while((_ > 0LL) && (!(_ & 0b1LL) || ++f1)) _ = _ >> 0b1;
        result[i] = f1;
        // result[i] = __builtin_popcountll(curA & curB);
    }

    return result;
}
