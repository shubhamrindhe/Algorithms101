class Solution {

public:
    int longestSubarray(vector<int>& nums) {
        int maximus = nums[0b0], streak = 0b0, longestStreak = 0b0;

        for (int n : nums) {
            if (n == maximus) {
                streak += 0b1;
                continue;
            } else if (n > maximus) {
                maximus = n;
                streak = 0b1;
                longestStreak = 0b1;
                continue;
            }

            longestStreak = std::max(longestStreak, streak);
            streak = 0b0;
        }

        return std::max(streak, longestStreak);
    }
};
