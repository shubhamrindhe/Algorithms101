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

    func ele() -> [Int] {
        var arr: [Int] = []
        arr.append(val)
        if let nextArray = next?.ele() {
            arr.append(contentsOf: nextArray)
        }
        return arr
    }
}

class Solution {

    func modifiedList(_ nums: [Int], _ head: ListNode?, _ elder: ListNode? = nil, _ set: Set<Int>? = nil) -> ListNode? {
        guard let head else {
            return nil
        }

//        var elder: ListNode?
//        var node: ListNode? = head
//        var newHead: ListNode?
//
//        let set = Set(nums)
//
//        repeat {
//            if let n = node {
//                if set.contains(n.val) {
//                    node = n.next
//                    elder?.next = nil
//                    continue
//                } else {
//                    if newHead == nil {
//                        newHead = node
//                    }
//
//                    elder?.next = n
//                    elder = n
//                    node = n.next
//                }
//            } else {
//                break
//            }
//        } while node != nil
//
//        return newHead

        let theSet = set ?? Set(nums)
        let next = modifiedList(nums, head.next, head, theSet)
        if theSet.contains(head.val) {
            elder?.next = next
            return next
        }

        return head
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
        ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    )?.ele(),
    [1,2,3,4]
)

// Input: nums = [1], head = [1,2,1,2,1,2]
// Output: [2,2,2]
print(
    solution.modifiedList(
        [1],
        ListNode(1, ListNode(2, ListNode(1, ListNode(2, ListNode(1, ListNode(2))))))
    )?.ele(),
    [2,2,2]
)

// Input: nums = [1,2,3], head = [1,2,3,4,5]
// Output: [4,5]
print(
    solution.modifiedList(
        [1,2,3],
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    )?.ele(),
    [4,5]
)
