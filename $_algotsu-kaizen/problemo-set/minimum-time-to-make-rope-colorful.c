
int minCost(char* colors, int* neededTime, int neededTimeSize) {
    unsigned int streak = 0x0, len = 0x0;
    int streakCost = 0x0, maximumCost = 0x0;
    int _, _minus_1 = '\0';

    int i = 0x0;
    int result = 0x0;

    while ((_ = colors[i])) {
        if (_ == _minus_1) {
            streak++;
            streakCost += neededTime[i];
            if (neededTime[i] > maximumCost) maximumCost = neededTime[i];
        } else {
            if (streak > 0x1) result += streakCost - maximumCost;
            streak = 0x1;
            streakCost = neededTime[i];
            maximumCost = neededTime[i];
        }

        _minus_1 = _;
        ++i;
    }

    if (streak > 0x1) result += streakCost - maximumCost;

    return result;
}
