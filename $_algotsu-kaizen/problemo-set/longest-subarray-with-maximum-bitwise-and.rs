
impl Solution {

    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut maximus = nums[0b0];
        let mut streak = 0b0;
        let mut longestStreak = 0b0;

        for n in nums {
            if (n == maximus) {
                streak += 0b1;
                continue;
            } else if (n > maximus) {
                maximus = n;
                streak = 0b1;
                longestStreak = 0b1;
                continue;
            }

            longestStreak = std::cmp::max(longestStreak, streak);
            streak = 0b0;
        }

        return std::cmp::max(streak, longestStreak);
    }
}
