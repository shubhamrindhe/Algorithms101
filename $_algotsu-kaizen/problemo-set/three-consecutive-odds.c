
bool threeConsecutiveOdds(int* arr, int arrSize) {
    for (int _ = 0b0, f = 0b0; _ < arrSize; ++_)
        if ((arr[_] % 0b10 ? ++f : (f = 0b0)) == 0b11) return true;
    return false;
}
