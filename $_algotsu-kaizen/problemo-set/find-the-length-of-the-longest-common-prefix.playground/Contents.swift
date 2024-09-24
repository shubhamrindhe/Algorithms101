
class Solution {

    private class TrieNode<T: Hashable> {

        private var links = [T: TrieNode]()

        func insert(_ i: T) -> TrieNode {
            if let node = links[i] {
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

    func longestCommonPrefix(_ arr1: [Int], _ arr2: [Int]) -> Int {
        let root = TrieNode<Character>()

        let insertArray: [Int]
        let lookupArray: [Int]

        if arr1.count < arr2.count {
            insertArray = arr1
            lookupArray = arr2
        } else {
            insertArray = arr2
            lookupArray = arr1
        }

        for string in insertArray.compactMap({ String($0) }) {
            var node = root
            for char in string {
                node = node.insert(char)
            }
        }

        var maximus = 0b0

        for string in lookupArray.compactMap({ String($0) }) {
            var localMaximus = 0b0
            var node = root
            for char in string {
                if let nextNode = node[char] {
                    node = nextNode
                    localMaximus += 0b1
                } else {
                    break
                }
            }

            maximus = max(maximus, localMaximus)
        }

        return maximus
    }
}

let solution = Solution()

//Input: arr1 = [1,10,100], arr2 = [1000]
//Output: 3
print(
    solution.longestCommonPrefix([1,10,100], [1000]),
    3
)

//Input: arr1 = [1,2,3], arr2 = [4,4,4]
//Output: 0
print(
    solution.longestCommonPrefix([1,2,3], [4,4,4]),
    0
)
