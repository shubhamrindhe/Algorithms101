/**
 * 1110. Delete Nodes And Return Forest
 * https://leetcode.com/problems/delete-nodes-and-return-forest/description/
 */

function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes_1 = function (node, to_delete, parent = null, assignData = {}, forest = []) {
    const dropNode = to_delete.includes(node.val)

    let newParent = node
    if (dropNode) {
        newParent = null
        if (parent) {
            Object.assign(parent, assignData)
        }
    } else {
        if (!parent) {
            forest.push(node)
        }
    }

    node?.left && delNodes(node.left, to_delete, newParent, { left: null }, forest)
    node?.right && delNodes(node.right, to_delete, newParent, { right: null }, forest)
    return forest
};


/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes = function (node, to_delete, parent = null, parentKai = {}, forest = []) {
    const dropNode = to_delete.includes(node.val)
    let nextParent = dropNode ? (parent && Object.assign(parent, parentKai) ? null : null) : ((parent || forest.push(node)) ? node : node)
    node?.left && delNodes(node.left, to_delete, nextParent, { left: null }, forest)
    node?.right && delNodes(node.right, to_delete, nextParent, { right: null }, forest)
    return forest
};

export { delNodes }

// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]
const inp1 = new TreeNode(
    1,
    new TreeNode(
        2,
        new TreeNode(4),
        new TreeNode(5),
    ),
    new TreeNode(
        3,
        new TreeNode(6),
        new TreeNode(7)
    ),
)
// console.log("$#",
//     JSON.stringify(delNodes(inp1, [3]), null, "\t"),
//     // delNodes(inp1, [3])
//     // [[1, 2, null, 4], [6], [7]],
// );

console.log("$#",
    JSON.stringify(delNodes(inp1, [1]), null, "\t"),
    // [[1, 2, null, 4], [6], [7]],
);
