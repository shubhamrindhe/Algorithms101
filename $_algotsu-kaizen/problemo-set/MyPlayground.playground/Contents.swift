import Foundation

class Solution {

    func tupleSameProduct(_ nums: [Int]) -> Int {
        var map = [Int: Int]()

        for i in 0..<nums.count {
            for j in (i + 1)..<nums.count {
                let product = nums[i] * nums[j]
                map[product, default: 0] += 1
                print("(\(i), \(j)) = \(product)")
            }
        }

        print(map)
        return 0
    }
}

let solution = Solution()

//Input: nums = [2,3,4,6]
//Output: 8
print(
    solution.tupleSameProduct([2,3,4,6]),
    8
)


//Input: nums = [1,2,4,5,10]
//Output: 16
print(
    solution.tupleSameProduct([1,2,4,5,10]),
    16
)
