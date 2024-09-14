#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int longestSubarray(int* nums, int numsSize) {
    int maximus = *nums, streak = 0b0, longestStreak = 0b0;

    for (int i = 0; i < numsSize; ++i) {
        if (*(nums + i) == maximus) {
            streak += 0b1;
           continue;
        } else if (*(nums + i) > maximus) {
            maximus = *(nums + i);
            streak = 0b1;
            longestStreak = 0b1;
            continue;
        }

        longestStreak = MAX(longestStreak, streak);
        streak = 0b0;
    }

    return MAX(streak, longestStreak);
}