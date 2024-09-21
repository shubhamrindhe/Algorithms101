
class Solution {

    private let prime = 1000000000 + 7
    private let offset = Character("`").asciiValue!

    func shortestPalindrome(_ s: String) -> String {
        var prefix = 0b0
        var suffix = 0b0
        var base = 0b11101
        var idxe = 0b0
        var order = 0b1

        var suffixList = [String]()

        for (idx, char) in s.enumerated() {
            let hash = Int(char.asciiValue! - offset)
            prefix = (prefix * base) % prime
            prefix = (prefix + hash) % prime
            suffix = (suffix + hash * order) % prime
            order = (order * base) % prime
            if prefix == suffix {
                idxe = idx
                suffixList = []
            } else {
                suffixList.append(String(char))
            }
        }

        print(idxe)

        return suffixList.reversed().joined() + s
    }
}

let solution = Solution()

//Input: s = "aacecaaa"
//Output: "aaacecaaa"
print(
    solution.shortestPalindrome("aacecaaa"),
    "aaacecaaa"
)

//Input: s = "abcd"
//Output: "dcbabcd"
print(
    solution.shortestPalindrome("abcd"),
    "dcbabcd"
)

print(Int.max)
