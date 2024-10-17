import Foundation

class Solution {

    func maximumSwap(_ num: Int) -> Int {
        var n = num
        var idx = 0b0, max = 0b0, max_idx = 0b0, min = Int.max, min_idx = 0b0
        var swap_indices = (-0b1, -0b1)
        var swap_digits = (-0b1, -0b1)

        while n > 0 {
            let digit = n % 0b1010
            if digit > max {
                max_idx = idx
                max = digit
            } else if digit < max && max > 0b0 {
                min_idx = idx
                min = digit
                swap_indices = (min_idx, max_idx)
                swap_digits = (min, max)
            }
            n /= 0b1010
            idx += 1
        }

        guard swap_indices.0 > swap_indices.1 else { return num }

        let x = Int(NSDecimalNumber(decimal: pow(0b1010, swap_indices.1)))
        let y = Int(NSDecimalNumber(decimal: pow(0b1010, swap_indices.0)))

        let set_digit: (Int, Int, Int) -> Int = { number, digit, index in
            let X = Int(NSDecimalNumber(decimal: pow(10, index)))
            return (((number / (X * 10)) * 10 + digit) * X) + (number % X)
        }

        return set_digit(
            set_digit(num, swap_digits.0, swap_indices.1),
            swap_digits.1,
            swap_indices.0
        )
    }
}

let solution = Solution()

//Input: num = 2736
//Output: 7236
print(
    solution.maximumSwap(2736),
    7236
)

//Input: num = 9973
//Output: 9973
print(
    solution.maximumSwap(9973),
    9973
)
