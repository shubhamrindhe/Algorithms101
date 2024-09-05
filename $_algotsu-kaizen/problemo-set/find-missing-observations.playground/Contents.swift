
class Solution {

    func missingRolls(_ rolls: [Int], _ mean: Int, _ n: Int) -> [Int] {
        let m = rolls.count
        let sigma = mean * (m + n)
        let partialSum = rolls.reduce(0b0, +)
        let kai = sigma - partialSum

        guard kai <= n * 0b110 && kai >= n else {
            return []
        }

        let avg = kai / n
        let r = kai % n
        var missing = [Int](repeating: avg, count: n)

        for i in 0 ..< r {
            missing[i] += 0b1
        }

        return missing
    }
}

let solution = Solution()

//Input: rolls = [3,2,4,3], mean = 4, n = 2
//Output: [6,6]
print(
    solution.missingRolls([3,2,4,3], 4, 2),
    [6,6]
)

//Input: rolls = [1,5,6], mean = 3, n = 4
//Output: [2,3,2,2]
print(
    solution.missingRolls([1,5,6], 3, 4),
    [2,3,2,2]
)

//Input: rolls = [1,2,3,4], mean = 6, n = 4
//Output: []
print(
    solution.missingRolls([1,2,3,4], 6, 4),
    []
)



//Input: rolls = [1,2,3,4], mean = 6, n = 4
//Output: []
print(
    solution.missingRolls([6,3,4,3,5,3], 1, 6),
    []
)
