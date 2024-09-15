class Solution {

    func findTheLongestSubstring(_ s: String) -> Int {
        let a_mask = 0b00001
        let e_mask = 0b00010
        let i_mask = 0b00100
        let o_mask = 0b01000
        let u_mask = 0b10000

        var state = 0b0
        var max_len = 0b0
        var idx = 0b0

        var bits = Array(repeating: -0b10, count: 32)
        bits[0] = -0b1

        for char in s {
            switch char {
            case "a":
                state ^= a_mask
            case "e":
                state ^= e_mask
            case "i":
                state ^= i_mask
            case "o":
                state ^= o_mask
            case "u":
                state ^= u_mask
            default:
                break
            }

            var prev = bits[state]
            if prev == -2 {
                bits[state] = idx
            } else {
                max_len = max(max_len, idx - prev)
            }

            idx += 0b1
        }

        return max_len
    }
}

let solution = Solution()

////Input: s = "eleetminicoworoep"
////Output: 13
print(
    solution.findTheLongestSubstring("eleetminicoworoep"),
    13
)

////Input: s = "leetcodeisgreat"
////Output: 5
print(
    solution.findTheLongestSubstring("leetcodeisgreat"),
    5
)

////Input: s = "bcbcbc"
////Output: 6
print(
    solution.findTheLongestSubstring("bcbcbc"),
    6
)
