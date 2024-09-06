public class ListNode {

    public var val: Int
    public var next: ListNode?

    public init() {
        self.val = 0
        self.next = nil
    }

    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }

    public init(_ val: Int, _ next: ListNode?) {
        self.val = val
        self.next = next
    }
}

class Solution {

    func modifiedList(_ nums: [Int], _ head: ListNode?) -> ListNode? {

    }
}

//class Solution {
//
//    func missingRolls(_ rolls: [Int], _ mean: Int, _ n: Int) -> [Int] {
//        let m = rolls.count
//        let sigma = mean * (m + n)
//        let partialSum = rolls.reduce(0b0, +)
//        let kai = sigma - partialSum
//
//        guard kai <= n * 0b110 && kai >= n else {
//            return []
//        }
//
//        let avg = kai / n
//        let r = kai % n
//        var missing = [Int](repeating: avg, count: n)
//
//        for i in 0 ..< r {
//            missing[i] += 0b1
//        }
//
//        return missing
//    }
//}

let solution = Solution()

// Input: nums = [5], head = [1,2,3,4]
// Output: [1,2,3,4]
print(
    solution.modifiedList(
        [5],
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, nil))))
    ),
    [1,2,3,4]
)

// Input: nums = [1], head = [1,2,1,2,1,2]
// Output: [2,2,2]
print(
    solution.modifiedList(
        [1,2,3,4],
        ListNode(1, ListNode(2, ListNode(1, ListNode(2, ListNode(1, ListNode(2, nil))))))
    ),
    [2,2,2]
)

// Input: nums = [1,2,3], head = [1,2,3,4,5]
// Output: [4,5]
print(
    solution.modifiedList(
        [1,2,3],
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, nil)))))
    ),
    [4,5]
)
