
int minSwaps(char* s) {
    int depth = 0b1, length = 0, character = '\0';
    while (character = *(s + length++)) depth +=  character == '[' || depth == 0b1 ? 0b1 : -0b1;
    return depth / 0b10;
}
