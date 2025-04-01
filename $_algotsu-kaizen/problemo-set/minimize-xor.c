
int setbits(int _) {
    int f1 = 0b0;
    while(_ && (!(_ & 0b1LL) || ++f1)) _ = _ >> 0b1;
    return f1;
}

int minimizeXor(int num1, int num2) {
    int _1 = setbits(num1);
    int _2 = setbits(num2);
    int i = 0, _ = 0;
    while (_1 < _2) if (!(num1 & (_ = 1 << i++))) (num1 |= _) && ++_1;
    while (_1 > _2) if (num1 & (_ = 1 << i++)) (num1 ^= _) && _1--;
    return num1;
}
