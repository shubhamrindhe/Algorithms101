/**
 * 145. Binary Tree Postorder Traversal
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 */

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var postorderTraversal = function(root, accumulator = []) {
    root.left && postorderTraversal(root.left, accumulator)
    root.right && postorderTraversal(root.right, accumulator)
    accumulator.push(root.val)
    return accumulator
};

export { postorderTraversal }

// Input: n = "123"
// Output: "121"
console.log("$#",
    postorderTraversal(
        "1234555"
    ),
    "121"
);

// Input: n = "1"
// Output: "0"
console.log("$#",
    postorderTraversal(
        "1"
    ),
    "0"
);


// 1234, 999, 1000
console.log("$#",
    postorderTraversal(
        "1234"
    ),
    "1221"
);
