/**
 * 1823. Find the Winner of the Circular Game
 * https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
 */

const circularDoublyLinkedList = (n, k) => {
    if (n == 1) return 1

    let node_one = null
    let node_last = null
    let count = 0, playerIDX = 0

    for (count = 1, playerIDX = 1; playerIDX <= n; ++playerIDX, ++count) {
        // if (count == k) { count = 0; continue; }
        const node = { last: node_last, $: playerIDX, next: null }

        if (!node_one) node_one = node
        if (node_last) node_last.next = node

        node_last = node

        if (playerIDX == n) {
            node_one.last = node_last
            node_last.next = node_one
        }
    }

    const drop = (_) => {
        if (_.last.$ == _.next.$ || _.last === _.next) {
            _.next.next = null
            _.next.last = null
            _.next = null
            _.last = null
            return
        }

        _.last.next = _.next
        _.next.last = _.last
    }

    let node = node_one
    count = 1
    while (node.next) {
        if (count == k) {
            let next = node.next
            drop(node)
            node = next
            count = 0
        } else {
            node = node.next
        }

        count++
    }

    return node.$
}

const queueShiftAndPush = (n, k) => {
    const QUEUE = new Array(n)
    for (let playerIDX = 0; playerIDX < n; ++playerIDX) {
        QUEUE[playerIDX] = playerIDX + 1
    }

    while (QUEUE.length > 1) {
        let i = k - 1
        while (i--) QUEUE.push(QUEUE.shift())
        QUEUE.shift()
    }

    return QUEUE.shift()
}

/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function (n, k) {
    // return circularDoublyLinkedList(n, k)
    // return queueShiftAndPush(n, k)
    const recursion = (n, k) => {
        if (n == 1) return 0
        return (recursion(n - 1, k) + k) % n
    }

    return recursion(n, k) + 1
};

export { findTheWinner }

// Input: n = 5, k = 2
// Output: 3
console.log("$#",
    findTheWinner(5, 2),
    3,
);

// Input: n = 6, k = 5
// Output: 1
console.log("$#",
    findTheWinner(6, 5),
    1,
);

console.log("$#",
    findTheWinner(2, 1),
    2,
);
console.log("$#",
    findTheWinner(6, 1),
    6,
);

console.log("$#",
    findTheWinner(2, 2),
    1,
);
console.log("$#",
    findTheWinner(6, 2),
    5,
);
