
int div_ceil(int a, int b) {
    return (a + b - 1) / b;
}

bool can_eat_all_in_time(int* piles, int pilesSize, int h, int eatingRate) {
    int hours_needed = 0;
    for (int i = 0; i < pilesSize; ++i) hours_needed += div_ceil(piles[i], eatingRate);
    // printf("[hours_needed] %d %d \n", hours_needed, eatingRate);
    return hours_needed <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int minimus = 0b1, maximus = piles[0], bananas = 0, eatingRate;
    for (int i = 1; i < pilesSize; i++) maximus < piles[i] && (maximus = piles[i]);
    // minimus > piles[i] && (minimus = piles[i]);
    // bananas += piles[i];

    while (minimus < maximus && (eatingRate = (maximus + minimus) / 2))
        // printf(" %d, %d, %d \n", l, eatingRate, r);
        (can_eat_all_in_time(piles, pilesSize, h, eatingRate) && (maximus = eatingRate)) || (minimus = eatingRate + 1);

    return minimus;
}
