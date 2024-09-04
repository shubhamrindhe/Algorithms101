
class Solution {
    func construct2DArray(_ original: [Int], _ m: Int, _ n: Int) -> [[Int]] {
        guard m * n == original.count else {
            return []
        }

        var matrix = [[Int]]()
        var idx = 0

        for r in 0 ..< m {
            var row = [Int](repeating: 0, count: n)
            for c in 0 ..< n {
                row[c] = original[idx]
                idx += 1
            }
            matrix.append(row)
        }

        return matrix
    }
}

let solution = Solution()

//Input: original = [1,2,3,4], m = 2, n = 2
//Output: [[1,2],[3,4]]
print(
    solution.construct2DArray([1,2,3,4], 2, 2),
    [[1,2],[3,4]]
)

//Input: original = [1,2,3], m = 1, n = 3
//Output: [[1,2,3]]
print(
    solution.construct2DArray([1,2,3], 1, 3),
    [[1,2,3]]
)

//Input: original = [1,2], m = 1, n = 1
//Output: []
print(
    solution.construct2DArray([1,2], 1, 1),
    []
)
