/**
 * 846. Hand of Straights
 * https://leetcode.com/problems/hand-of-straights/description/
 */

class Node {
    constructor(val = null, l = null, r = null) {
        this.val = val
        this.l = l
        this.r = r
    }
}

class Tree {

    constructor(val) {
        this.root = new Node(val)
    }

    seek(val) {
        let node = this.root

        while (node) {
            if (val < node.val) {
                if (node.l) node = node.l
                else break
            } else if (val > node.val) {
                if (node.r) node = node.r
                else break
            } else {
                break
            }
        }

        return node
    }

    insert(val) {
        let node = this.seek(val)
        console.log(node);

        if (val < node.val) {
            if (!node.l) {
                node.l = new Node(val)
                return true
            } else {

            }
        } else if (val > node.val) {
            if (!node.r) {
                node.r = new Node(val)
                return true
            } else {

            }
        } else {

        }
    }
}

const inorder = (node, acc = []) => {
    if (!node) return acc
    inorder(node.l, acc)
    acc.push(node.val)
    inorder(node.r, acc)
    return acc
}

/**
 * @param {number[]} hand
 * @param {number} groupSize
 * @return {boolean}
 */
var isNStraightHand = function (hand, groupSize) {
    if (hand.length < Math.pow(groupSize, 2)) return false
    let map = new Map()

    hand.forEach(e => {
        let count = map.get(e) || 0
        map.set(e, ++count)
    })

    // console.log(map);
    for (let [key, val] of map.entries())  {
        if (val > 0) {
            for (let i = key; i < key + groupSize; ++i) {
                let i_val = map.get(i) || 0
                map.set(i, i_val - val)
                if (i_val - val < 0) return false
            }
        }
    }

    return true
        

    // let groupData = (size) => {
    //     return {
    //         data: new Array(size),
    //         size: 0,
    //         min: 0,
    //         max: Infinity
    //     }
    // }

    // let group = new Array(groupSize)
};

export { isNStraightHand }

// let tree = new Tree(3)
// tree.insert(2)
// tree.insert(5)
// tree.insert(10)
// tree.insert(1)

// console.log(tree);

// console.log(inorder(tree.root));

console.log("$#", isNStraightHand([1, 2, 3, 6, 2, 3, 4, 7, 8], 3));
// console.log("$#", isNStraightHand(["cool", "lock", "cook"]));
