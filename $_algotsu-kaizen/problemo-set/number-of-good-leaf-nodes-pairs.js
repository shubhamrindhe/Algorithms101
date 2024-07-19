/**
 * 1530. Number of Good Leaf Nodes Pairs
 * https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
 */

function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @param {number} distance
 * @return {number}
 */
var countPairs_ = function (root, distance) {
    let count = 0

    const dfs = (node, dist) => {
        if (!node.left && !node.right) return [[1, node]]

        let left_d = node?.left ? dfs(node.left, dist) : []
        let right_d = node?.right ? dfs(node.right, dist) : []

        // for (let [dl, lf_node] of left_d) {
        //     for (let [dr, rf_node] of right_d) {
        //         // console.log(dl, lf_node, dr, rf_node);
        //         console.log(dl, dr);
        //         if ((dl++) + (dr++) <= dist) count++
        //         console.log(dl, dr);
        //     }
        // }

        for (let i = 0; i < left_d.length; ++i) {
            for (let j = 0; j < right_d.length; ++j) {
                // console.log(left_d[i][1], right_d[j][1]);
                if ((left_d[i][0]++) + (right_d[j][0]++) < dist) {
                    console.log(left_d[i][0], right_d[j][0]);
                    console.log(left_d[i][1], right_d[j][1]);
                    count++
                }
                // console.log(left_d[i], right_d[j]);
            }
        }

        // return [].concat.apply([], [left_d, right_d])
        return [...left_d, ...right_d]
    }

    dfs(root, distance)

    return count
};


var countPairs = function (root, distance) {
    let count = 0

    const dfs = (node) => {
        if (!node.left && !node.right) return [1]
        let left_leaves_d = node?.left ? dfs(node.left) : []
        let right_leaves_d = node?.right ? dfs(node.right) : []
        for (const left_leaf of left_leaves_d)
            for (const right_leaf of right_leaves_d)
                if (left_leaf + right_leaf <= distance) ++count
        left_leaves_d.forEach((e, i, l) => { ++l[i] })
        right_leaves_d.forEach((e, i, l) => { ++l[i] })
        return [...left_leaves_d, ...right_leaves_d]
    }

    dfs(root, distance)

    return count
};

export { countPairs }


// [1,2,3].forEach((e, l, i) => { console.log(e, l, i); })


// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
const inp1 = new TreeNode(
    1,
    new TreeNode(
        2,
        null,
        new TreeNode(4),
    ),
    new TreeNode(
        3,
    ),
)
console.log("$#",
    countPairs(inp1, 3),
    1,
);

const inp2 = new TreeNode(
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
// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
console.log("$#",
    countPairs(inp2, 3),
    2
    // delNodes(inp1, [3])
    // [[1, 2, null, 4], [6], [7]],
);

const inp3 = new TreeNode(
    7,
    new TreeNode(
        1,
        new TreeNode(6),
        // new TreeNode(5),
    ),
    new TreeNode(
        4,
        new TreeNode(5),
        new TreeNode(
            3,
            null,
            new TreeNode(2)
        )
    ),
)
// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
console.log("$#",
    countPairs(inp3, 3),
    1
    // delNodes(inp1, [3])
    // [[1, 2, null, 4], [6], [7]],
);

// [
//       7
//     1    4
//   6  0  5  3
// 0  0 null,null,null,2