
import Foundation

class Solution {

    func minLength(_ s: String) -> Int {
        var stack = [Character]()

        for character in s {
            switch character {
            case "B":
                if stack.last == "A" {
                    stack.popLast()
                    continue
                }
            case "D":
                if stack.last == "C" {
                    stack.popLast()
                    continue
                }
            default:
                break
            }

            stack.append(character)
        }

        return stack.count
    }
}

let solution = Solution()

//Input: s = "ABFCACDB"
//Output: 2
print(
    solution.minLength("ABFCACDB"),
    2
)

//Input: s = "ACBBD"
//Output: 5
print(
    solution.minLength("ACBBD"),
    5
)
