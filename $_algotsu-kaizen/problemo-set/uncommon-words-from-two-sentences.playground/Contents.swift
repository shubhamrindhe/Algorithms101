class Solution {
    func uncommonFromSentences(_ s1: String, _ s2: String) -> [String] {
        var frequencyTable = [String: Int]()

        for word in s1.split(separator: " ") {
            frequencyTable[String(word)] = (frequencyTable[String(word)] ?? 0b0) + 0b1
        }

        for word in s2.split(separator: " ") {
            frequencyTable[String(word)] = (frequencyTable[String(word)] ?? 0b0) + 0b1
        }

        var result = [String]()

        for (word, count) in frequencyTable {
            if count == 0b1 {
                result.append(word)
            }
        }

        return result
    }
}

let solution = Solution()

//Input: s1 = "this apple is sweet", s2 = "this apple is sour"
//Output: ["sweet","sour"]
print(
    solution.uncommonFromSentences("this apple is sweet", "this apple is sour"),
    ["sweet","sour"]
)


//Input: s1 = "apple apple", s2 = "banana"
//Output: ["banana"]
print(
    solution.uncommonFromSentences("apple apple", "banana"),
    ["banana"]
)
