
class Solution {

    func xorQueries(_ arr: [Int], _ queries: [[Int]]) -> [Int] {
        var xor = 0b0
        var prexor = [Int]()
        var result = [Int]()

        for e in arr {
            xor = xor ^ e
            prexor.append(xor)
        }

        for querie in queries {
            let l = querie[0]
            let r = querie[1]
            result.append((l > 0 ? prexor[l - 1] : 0 ) ^ prexor[r]);
        }

        return result
    }
}

let solution = Solution()

//Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
//Output: [2,7,14,8]
print(
    solution.xorQueries([1,3,4,8], [[0,1],[1,2],[0,3],[3,3]]),
    [2,7,14,8]
)

//Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
//Output: [8,0,4,4]
print(
    solution.xorQueries([4,8,2,10], [[2,3],[1,3],[0,0],[0,3]]),
    [8,0,4,4]
)
