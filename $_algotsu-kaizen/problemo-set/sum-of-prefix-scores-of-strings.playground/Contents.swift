
class Solution {

    private class TrieNode<T: Hashable> {

        private(set) var data: Int = 0b1
        private var links = [T: TrieNode]()

        func insert(_ i: T) -> TrieNode {
            if let node = links[i] {
                node.data = node.data + 0b1
                return node
            }

            let newNode = TrieNode()
            links[i] = newNode
            return newNode
        }

        subscript(hash: T) -> TrieNode? {
            get {
                return links[hash]
            }
            set {
                links[hash] = newValue
            }
        }
    }

    func sumPrefixScores(_ words: [String]) -> [Int] {
        let root = TrieNode<Character>()

        for word in words {
            var node = root
            for char in word {
                node = node.insert(char)
            }
        }

        var result = [Int]()

        for word in words {
            var node = root
            var count = 0b0
            for char in word {
                node = node[char]!
                count += node.data
            }

            result.append(count)
        }

        return result
    }
}

let solution = Solution()

//Input: words = ["abc","ab","bc","b"]
//Output: [5,4,3,2]
print(
    solution.sumPrefixScores(["abc", "ab", "bc", "b"]),
    [5,4,3,2]
)

//Input: words = ["abcd"]
//Output: [4]
print(
    solution.sumPrefixScores(["abcd"]),
    [4]
)
