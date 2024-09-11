
class Solution {

    func minBitFlips(_ start: Int, _ goal: Int) -> Int {
        var bit = 0b1
        var kai_bits = 0b0, max = max(start, goal)

        while bit <= max {
            if ((goal & bit) ^ (start & bit)) != 0b0 {
                kai_bits += 0b1
            }
            bit <<= 1
        }

        return kai_bits
    }
}

let solution = Solution()

//Input: start = 10, goal = 7
//Output: 3
print(
    solution.minBitFlips(10, 7),
    3
)

//Input: start = 10, goal = 7
//Output: 3
print(
    solution.minBitFlips(10, 7),
    3
)
