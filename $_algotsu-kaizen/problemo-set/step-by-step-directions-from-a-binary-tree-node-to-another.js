/**
 * 2096. Step-By-Step Directions From a Binary Tree Node to Another
 * https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
 */

function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @param {number} startValue
 * @param {number} destValue
 * @return {string}
 */
var getDirections = function (root, startValue, destValue) {
    const crawl = (node, target, trail) => {
        if (node.val == target) {
            trail.push('.')
            return trail
        }

        let pathway = null

        if (node.left) {
            trail.push('L')
            pathway = crawl(node.left, target, trail)
            if (!pathway) trail.pop()
        }

        if (!pathway && node.right) {
            trail.push('R')
            pathway = crawl(node.right, target, trail)
            if (!pathway) trail.pop()
        }

        return pathway
    }

    const path2S = crawl(root, startValue, [])
    const path2D = crawl(root, destValue, [])

    let i = 0
    while ((i < path2S.length - 1) && (i < path2D.length - 1)) {
        if (path2S[i] != path2D[i]) break
        ++i
    }

    const IDX = i
    let direction = ''
    for (i = IDX; i < path2S.length - 1; ++i) direction += 'U'
    for (i = IDX; i < path2D.length - 1; ++i) direction += path2D[i]

    return direction
};

export { getDirections }

// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
const inp1 = new TreeNode(
    5,
    new TreeNode(
        1,
        new TreeNode(3),
    ),
    new TreeNode(
        2,
        new TreeNode(6),
        new TreeNode(4)
    ),
)
console.log("$#",
    getDirections(inp1, 3, 6),
    "UURL",
);
console.log("$#",
    getDirections(inp1, 3, 3),
    "",
);

console.log("$#",
    getDirections(inp1, 3, 5),
    "UU",
);
console.log("$#",
    getDirections(inp1, 1, 4),
    "URR",
);

// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.
const inp2 = new TreeNode(
    2,
    new TreeNode(1)
)
console.log("$#",
    getDirections(inp2, 2, 1),
    "L",
);
