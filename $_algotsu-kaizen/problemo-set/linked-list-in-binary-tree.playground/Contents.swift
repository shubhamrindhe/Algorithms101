
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() { self.val = 0; self.left = nil; self.right = nil; }
    public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}

class Solution {

    private func select(node: TreeNode, value: Int) -> [TreeNode] {
        var list = [TreeNode]()

        if node.val == value {
            list.append(node)
        }

        if let left = node.left {
            list.append(contentsOf: select(node: left, value: value))
        }

        if let right = node.right {
            list.append(contentsOf: select(node: right, value: value))
        }

        return list
    }

    private func check(node: TreeNode, item: ListNode) -> Bool {
        guard node.val == item.val else {
            return false
        }

        guard let next = item.next else {
            return true
        }

        var leftResult = node.left != nil
        if let left = node.left {
            leftResult = check(node: left, item: next)
        }

        var rightResult = node.right != nil
        if let right = node.right {
            rightResult = check(node: right, item: next)
        }

        return leftResult || rightResult
    }

    func isSubPath(_ head: ListNode?, _ root: TreeNode?) -> Bool {
        guard let head, let root else {
            return false
        }

        for node in select(node: root, value: head.val) {
            if check(node: node, item: head) {
                return true
            }
        }

        return false
    }
}

let solution = Solution()

let tree = TreeNode(
    1,
    TreeNode(
        4,
        nil,
        TreeNode(
            2,
            TreeNode(1, nil, nil),
            nil)
    ),
    TreeNode(
        4,
        TreeNode(
            2,
            TreeNode(
                6,
                nil,
                nil
            ),
            TreeNode(
                8,
                TreeNode(1, nil, nil),
                TreeNode(3, nil, nil))),
        nil)
)

// Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
// Output: true
print(
    solution.isSubPath(
        ListNode(4, ListNode(2, ListNode(8))),
        tree
    ),
    true
)

// Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
// Output: true
print(
    solution.isSubPath(
        ListNode(1, ListNode(4, ListNode(2, ListNode(6)))),
        tree
    ),
    true
)

// Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
// Output: false
print(
    solution.isSubPath(
        ListNode(1, ListNode(4, ListNode(2, ListNode(6, ListNode(8))))),
        tree
    ),
    false
)
