
class Solution {

    func smallestRange(_ nums: [[Int]]) -> [Int] {
        var idxs = [Int](repeating: 0, count: nums.count)
        var start = 0
        var end = Int.max

        while true {
            var min = Int.max
            var max = Int.min
            var minIdx = 0
            for (idx, i) in idxs.enumerated() {
                let n = nums[idx][i]
                if n < min { (min, minIdx) = (n, idx) }
                if n > max { max = n }
            }

            if end - start > max - min {
                start = min
                end = max
            }

            if nums[minIdx].count - 1 == idxs[minIdx] {
                break
            }

            idxs[minIdx] += 0b1
        }

        return [start, end]
    }
}

let solution = Solution()

//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
print(
    solution.smallestRange([[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]),
    [20, 24]
)

//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
print(
    solution.smallestRange([[1, 2, 3], [1, 2, 3], [1, 2, 3]]),
    [1, 1]
)
