class Solution {

    func minAddToMakeValid(_ s: String) -> Int {
        let result = 0
        var stack = [Character]()

        for c in s {
            if c == ")", let top = stack.last, top == "(" {
                stack.popLast()
            } else {
                stack.append(c)
            }
        }

        return stack.count
    }
}

let solution = Solution()

//Input: s = "())"
//Output: 1
print(
    solution.minAddToMakeValid("())"),
    2
)

//Input: s = "((("
//Output: 3
print(
    solution.minAddToMakeValid("((("),
    0
)
