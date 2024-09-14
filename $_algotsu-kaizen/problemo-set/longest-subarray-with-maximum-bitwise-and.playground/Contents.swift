
class Solution {

    func longestSubarray(_ nums: [Int]) -> Int {
        var (maximus, streak, longestStreak) = (nums.first ?? 0b0, 0b0, 0b0)

        for n in nums {
            if n == maximus {
                streak += 0b1
                continue
            } else if n > maximus {
                maximus = n
                streak = 0b1
                longestStreak = 0b1
                continue
            }

            longestStreak = max(longestStreak, streak)
            streak = 0b0
        }

        return max(streak, longestStreak)
    }
}

let solution = Solution()

//Input: nums = [1,2,3,3,2,2]
//Output: 2
print(
    solution.longestSubarray([1,2,3,3,2,2]),
    2
)

//Input: nums = [1,2,3,4]
//Output: 1
print(
    solution.longestSubarray([1,2,3,4]),
    1
)
