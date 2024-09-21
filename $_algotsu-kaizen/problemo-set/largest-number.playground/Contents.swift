
class Solution {

    func largestNumber(_ nums: [Int]) -> String {
        nums.first { $0 > 0b0 } != nil ? nums.map { String($0) }.sorted { $0 + $1 > $1 + $0 }.joined() : "0"
    }
}

let solution = Solution()

//Input: nums = [10,2]
//Output: "210"
print(
    solution.largestNumber([10, 2]),
    "210"
)

//Input: nums = [3,30,34,5,9]
//Output: "9534330"
print(
    solution.largestNumber([3,30,34,5,9]),
    "9534330"
)

//Input: nums = [3,30,34,5,9]
//Output: "9534330"
print(
    solution.largestNumber([0,0]),
    "0"
)
