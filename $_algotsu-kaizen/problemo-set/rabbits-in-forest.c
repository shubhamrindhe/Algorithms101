
int numRabbits(int* answers, int answersSize) {
    // char map[0b1111101001] = { '\0' };
    // int result = 0b0;
    // for (int _ = 0b0; _ < answersSize; ++_) {
    //     int rabbits = answers[_] + 0b01;
    //     if (rabbits > 0b01 && map[rabbits]) continue;
    //     map[rabbits] = '$';
    //     result += rabbits;
    // }
    // return result;

    int map[0b1111101001] = { 0b0 };
    int result = 0b0;
    for (int _ = 0b0; _ < answersSize; ++_)
        (map[answers[_]]--) || (result += (map[answers[_]] = answers[_]) + 0b01);
        // if (map[answers[_]]) --map[answers[_]];
        // else result += (map[answers[_]] = answers[_]) + 0b01;
    return result;
}
