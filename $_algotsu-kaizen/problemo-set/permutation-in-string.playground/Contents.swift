
class Solution {

    func checkInclusion(_ s1: String, _ s2: String) -> Bool {
        guard s1.count <= s2.count else { return false }

        let fmap = s1.reduce(into: [Character: Int]()) { result, char in result[char, default: 0] += 1 }

        let size = s1.count

        var freq = Dictionary(s2.prefix(size).map { ($0, 1) }, uniquingKeysWith: +)
        let matchFrequencies = { freq.keys.allSatisfy { fmap[$0] == freq[$0] } }

        if matchFrequencies() { return true }

        for index in size..<s2.count {
            let startIndex = s2.index(s2.startIndex, offsetBy: index)
            let endIndex = s2.index(s2.startIndex, offsetBy: index - size)

            let startCharacter = s2[startIndex]
            let endCharacter = s2[endIndex]

            freq[startCharacter, default: 0] += 1
            freq[endCharacter, default: 0] -= 1

            if freq[endCharacter] == 0 {
                freq.removeValue(forKey: endCharacter)
            }

            if matchFrequencies() { return true }
        }

        return false
    }
}

let solution = Solution()

//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
print(
    solution.checkInclusion("ab", "eidbaooo"),
    true
)

//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
print(
    solution.checkInclusion("ab", "eidboaoo"),
    false
)
