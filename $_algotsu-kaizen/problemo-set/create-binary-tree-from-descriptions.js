/**
 * 726. Number of Atoms
 * https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
 */

function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
var createBinaryTree = function (descriptions) {
    const map = new Map()
    // const rootFlagMap = new Map()
    const childrenSet = new Set()

    for (const [parent, child, isLeft] of descriptions) {
        const childNode = map.get(child) || new TreeNode(child)
        const parentNode = map.get(parent) || new TreeNode(parent)
        isLeft ? parentNode.left = childNode : parentNode.right = childNode
        !map.has(parent) && map.set(parent, parentNode)
        !map.has(child) && map.set(child, childNode)
        // !rootFlagMap.has(parent) && rootFlagMap.set(parent, true)
        // rootFlagMap.set(child, false)
        childrenSet.add(child)
    }

    for (const [key, node] of map.entries()) {
        if (childrenSet.has(key)) continue
        return node
    }
};

export { createBinaryTree }

// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
console.log("$#",
    createBinaryTree([[20, 15, 1], [20, 17, 0], [50, 20, 1], [50, 80, 0], [80, 19, 1]]),
    [50, 20, 80, 15, 17, 19],
);

// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
console.log("$#",
    createBinaryTree([[1, 2, 1], [2, 3, 0], [3, 4, 1]]),
    [1, 2, null, null, 3, 4],
);
