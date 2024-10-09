
class Solution {

    func minSwaps(_ s: String) -> Int {
        var stack = [Character]()

        for c in s {
            if c == "]" && stack.last == "[" {
                stack.popLast()
            } else {
                stack.append(c)
            }
        }

        return ((stack.count / 2) + 1) / 2
    }
}

let solution = Solution()

//Input: s = "][]["
//Output: 1
print(
    solution.minSwaps("][]["),
    1
)

//Input: s = "]]][[["
//Output: 2
print(
    solution.minSwaps("]]][[["),
    2
)

//Input: s = "[]"
//Output: 0
print(
    solution.minSwaps("[]"),
    0
)
