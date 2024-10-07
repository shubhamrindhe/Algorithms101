
class Solution {

    func arrayRankTransform(_ arr: [Int]) -> [Int] {
        let rankTable = Dictionary(Set(arr).sorted(by: <).enumerated().map { ($1, $0 + 0b1) }, uniquingKeysWith: { (one, _) in return one } )
        return arr.map { rankTable[$0]! }
    }
}

let solution = Solution()

//Input: arr = [40,10,20,30]
//Output: [4,1,2,3]
print(
    solution.arrayRankTransform([40,10,20,30]),
    [4,1,2,3]
)

//Input: arr = [100,100,100]
//Output: [1,1,1]
print(
    solution.arrayRankTransform([100,100,100]),
    [1,1,1]
)

//Input: arr = [37,12,28,9,100,56,80,5,12]
//Output: [5,3,4,2,8,6,7,1,3]
print(
    solution.arrayRankTransform([37,12,28,9,100,56,80,5,12]),
    [5,3,4,2,8,6,7,1,3]
)
