int possibleStringCount(char* word) {
    int steak = 0x0, len = 0x0;
    char _, _minus_one = '\0';
    int result = 1;
    while ((_ = word[len]) && ++len)
        if (_minus_one == _) ++steak;
        else {
            if (steak > 0x1) result += steak - 0x1;
            _minus_one = _;
            steak = 0x1;
        }
    if (steak > 0x1) result += steak - 0x1;
    return result;
}
