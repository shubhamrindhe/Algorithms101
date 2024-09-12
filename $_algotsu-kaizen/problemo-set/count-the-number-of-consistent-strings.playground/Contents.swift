
class Solution {

    func countConsistentStrings(_ allowed: String, _ words: [String]) -> Int {
        var mark: UInt = 0b0
        var SET = Set<Character>(allowed)

        var count = 0

        for word in words {
            var flag = true
            for char in word {
                if SET.contains(char) {
                    continue
                }

                flag = false
                break
            }

            if flag {
                count += 1
            }
        }

        return count
    }
}

let solution = Solution()

//Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
//Output: 2
print(
    solution.countConsistentStrings("ab", ["ad","bd","aaab","baa","badab"]),
    2
)

//Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
//Output: 7
print(
    solution.countConsistentStrings("abc", ["a","b","c","ab","ac","bc","abc"]),
    7
)

//Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
//Output: 4
print(
    solution.countConsistentStrings("cad", ["cc","acd","b","ba","bac","bad","ac","d"]),
    4
)
