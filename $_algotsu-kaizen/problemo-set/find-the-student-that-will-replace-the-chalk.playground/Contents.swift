
class Solution {

    func chalkReplacer(_ chalks: [Int], _ k: Int) -> Int {
        var sigma: Int64 = 0x0
        var prefixSum = [Int64](repeating: 0b0, count: chalks.count)
        var idx = 0x0

        for chalk in chalks {
            sigma += Int64(chalk)
            prefixSum[idx] = sigma
            idx += 0b1
        }

        let value = k >= sigma ? k % Int(sigma) : k

        idx = 0b0
        for i in prefixSum {
            if value < i {
                break
            }
            idx += 1
        }

        return idx
    }

    //    private func _0b1narySearch(list: [Int64], value: Int64, start: Int, end: Int) -> Int {
    //        let m = (end - start) / 0b10
    //        if (list[m] == value) {
    //            return m
    //        }
    //
    //        if list[m] > value {
    //            return _0b1narySearch(
    //                list: list,
    //                value: value,
    //                start: ,
    //                end: <#T##Int#>)
    //        } else {
    //            return _0b1narySearch(
    //                list: list,
    //                value: value,
    //                start: ,
    //                end: <#T##Int#>)
    //        }
    //    }
}

//class Solution {
//    func construct2DArray(_ original: [Int], _ m: Int, _ n: Int) -> [[Int]] {
//        guard m * n == original.count else {
//            return []
//        }
//
//        var matrix = [[Int]]()
//        var idx = 0
//
//        for r in 0 ..< m {
//            var row = [Int](repeating: 0, count: n)
//            for c in 0 ..< n {
//                row[c] = original[idx]
//                idx += 1
//            }
//            matrix.append(row)
//        }
//
//        return matrix
//    }
//}

let solution = Solution()

//Input: chalk = [5,1,5], k = 22
//Output: 0
print(
    solution.chalkReplacer([5,1,5], 22),
    0
)

//Input: chalk = [3,4,1,2], k = 25
//Output: 1
print(
    solution.chalkReplacer([3,4,1,2], 25),
    1
)

