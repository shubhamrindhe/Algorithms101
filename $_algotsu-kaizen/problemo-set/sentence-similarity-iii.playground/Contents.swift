
import Foundation

class Solution {

    func areSentencesSimilar(_ sentence1: String, _ sentence2: String) -> Bool {
        var wordListOne = sentence1.components(separatedBy: .whitespaces)
        var wordListTwo = sentence2.components(separatedBy: .whitespaces)

        var i = 0
        var j = wordListOne.count - 1
        var k = wordListTwo.count - 1
        var result = true

        while i <= min(j, k) {
            if wordListOne[i] == wordListTwo[i] {
                i += 1
            } else if wordListOne[j] == wordListTwo[k] {
                j -= 1
                k -= 1
            } else {
                result = false
                break
            }
        }

        return result
    }
}

let solution = Solution()

//Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
//Output: true
print(
    solution.areSentencesSimilar("My name is Haley", "My Haley"),
    true
)

//Input: sentence1 = "of", sentence2 = "A lot of words"
//Output: false
print(
    solution.areSentencesSimilar("of", "A lot of words"),
    false
)

//Input: sentence1 = "Eating right now", sentence2 = "Eating"
//Output: true
print(
    solution.areSentencesSimilar("Eating right now", "Eating"),
    true
)
