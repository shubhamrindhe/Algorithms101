
class Solution {



    func generate(i: Int, n: Int) -> [Int] {
        i > n ? [] : [i] + generate(i: i * 10, n: n) + (i % 10 < 9 ? generate(i: i + 1, n: n) : [])
//        var result = [Int]()
//
//        var max = 0
//
//        if i < n {
//            result.append(i)
//            max = i
//        }
//
//        var breakFlag = false
//
//        let digits = [1, 2, 3, 4, 5, 6, 7, 8, 9]
//
//        var multiplier = 10
//
//
//
//        while result.count < n {
//            var newNums = [Int]()
//            for n in result {
//                let nn = n * 10
//                for digit in digits {
//                    let newNum = nn + digit
//
//                    if newNum <= n {
//                        newNums.append(newNum)
//                    }
//                }
//            }
//
//            result.append(contentsOf: newNums)
//        }
//
//        return result
    }

    func lexicalOrder(_ n: Int) -> [Int] {
        return generate(i: 1, n: n)
    }
}

let solution = Solution()

//Input: n = 13
//Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
print(
    solution.lexicalOrder(13),
    [1,10,11,12,13,2,3,4,5,6,7,8,9]
)

//Input: n = 2
//Output: [1,2]
print(
    solution.lexicalOrder(2),
    [1,2]
)


print(solution.generate(i: 1, n: 13))
