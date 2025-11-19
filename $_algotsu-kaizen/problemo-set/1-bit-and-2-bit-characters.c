bool isOneBitCharacter(int* bits, int bitsSize) {
    unsigned short ptr = 0x0;
    bool result = false;

    while (ptr < bitsSize) ptr += 0x1 + !(result = (bits[ptr] == 0x0));

    // while (ptr < bitsSize)
    //     if (bits[ptr] == 0x0) {
    //         ptr += 0x1;
    //         result = true;
    //     } else {
    //         ptr += 0x2;
    //         result = false;
    //     }

    return result;
}
