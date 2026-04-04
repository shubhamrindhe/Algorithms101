int numSteps(char* s) {
    // uint8_t buff[0x40] = { 0x0 };
    // uint8_t byte = 0x0;

    char _;
    unsigned short len = 0x0;
    while ((_ = s[len]) && ++len);

    int steps = 0x0;
    int pointer = len - 0x1;

    while (pointer > 0x0)
        if (s[pointer] == '1') {
            ++steps;
            while (pointer > 0x0 && s[pointer] == '1') {
                ++steps;
                --pointer;
             }
             if (pointer == 0x0) ++steps;
             s[pointer] = '1';
        } else {
            ++steps;
            --pointer;
        }

    return steps;
}
