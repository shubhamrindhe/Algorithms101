class Solution {

    func findMinDifference(_ timePoints: [String]) -> Int {
        var minutes = [Int]()

        for time in timePoints {
            let HH_MM = time.split(separator: ":")
            let HH = Int(HH_MM.first!)!
            let MM = Int(HH_MM.last!)!
            let minutes_ = HH * 60 + MM
            minutes.append(minutes_)
            if minutes_ < (1440 / 2) {
                minutes.append(minutes_ + 1440)
            }
        }

        minutes.sort()
        var result = Int.max;
        for i in 0 ..< minutes.count - 1 {
            result = min(result, minutes[i+1] - minutes[i])
        }

        return result
    }
}

class Solution1 {

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

//Input: timePoints = ["23:59","00:00"]
//Output: 1
print(
    solution.findMinDifference(["23:59","00:00"]),
    1
)

//Input: timePoints = ["00:00","23:59","00:00"]
//Output: 0
print(
    solution.findMinDifference(["00:00","23:59","00:00"]),
    0
)
