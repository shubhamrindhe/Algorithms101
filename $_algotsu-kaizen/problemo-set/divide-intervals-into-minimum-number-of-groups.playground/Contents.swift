
class Solution {

    typealias OverlapingInterval = (start: Int, end: Int, count: Int)
    typealias Interval = (start: Int, end: Int)

    func isNonOverlapping(_ s1: Int, _ e1: Int, _ s2: Int, _ e2: Int) -> Bool {
        e2 < s1 || e1 < s2
    }

    func minGroups(_ intervals: [[Int]]) -> Int {
        var result = 1
        var nonoverlapping = [Interval]()
        var overlapping = [OverlapingInterval]()

        for interval in intervals {
            let start = interval.first!, end = interval.last!
            var isOverlapping = false

            for oi in overlapping {
                if !isNonOverlapping(start, end, oi.start, oi.end) {
                    overlapping.append((max(start, oi.start), min(end, oi.end), oi.end + 1))
                    result = max(result, oi.end + 1)
                    isOverlapping = true
                }
            }

            if !isOverlapping {
                for i in nonoverlapping {
                    if !isNonOverlapping(start, end, i.start, i.end) {
                        overlapping.append(
                            (
                                max(start, i.start),
                                min(end, i.end),
                                2
                            )
                        )

                        result = max(result, 2)

                        isOverlapping = true
                        break
                    }
                }
            }

            nonoverlapping.append((start, end))
        }

        return result
    }
}

let solution = Solution()

//Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
//Output: 3
print(
    solution.minGroups([[5, 10], [6, 8], [1, 5], [2, 3], [1, 10]]),
    3
)

//Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
//Output: 1
print(
    solution.minGroups([[1, 3], [5, 6], [8, 10], [11, 13]]),
    1
)
