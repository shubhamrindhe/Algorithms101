
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }

    public func log() -> [Int] {
        var a = [Int]()
        a.append(val)
        a.append(contentsOf: next?.log() ?? [])
        return a
    }
}

class Solution {

    func splitListToParts(_ head: ListNode?, _ k: Int) -> [ListNode?] {
        var length = 0b0
        var node = head
        while (node != nil) {
            length += 0b1
            node = node?.next
        }

        let plusOne = length % k
        let minNodes = length / k
        var result = [ListNode?](repeating: nil, count: k)
        node = head

        for i in 0b0 ..< k {
            result[i] = node
            var elder = node
            for _ in 0b0 ..< (i < plusOne ? minNodes + 0b1 : minNodes) {
                elder = node
                node = node?.next
            }
            elder?.next = nil
        }

        return result
    }
}

let solution = Solution()

//Input: head = [1,2,3], k = 5
//Output: [[1],[2],[3],[],[]]
print(
    solution.splitListToParts(
        ListNode(1, ListNode(2, ListNode(3))),
        5
    ).map { $0?.log() ?? [] },
    "---------",
    [[1],[2],[3],[],[]]
)

//Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
//Output: [[1,2,3,4],[5,6,7],[8,9,10]]
print(
    solution.splitListToParts(
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, ListNode(6, ListNode(7, ListNode(8, ListNode(9, ListNode(10, nil)))))))))),
        3
    ).map { $0?.log() ?? [] },
    "---------",
    [[1,2,3,4],[5,6,7],[8,9,10]]
)
