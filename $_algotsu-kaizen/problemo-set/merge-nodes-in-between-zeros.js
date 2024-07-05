/**
 * 2181. Merge Nodes in Between Zeros
 * https://leetcode.com/problems/merge-nodes-in-between-zeros/
 */

// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

const LikedListFromAray = (_) => {
    return _.reverse().reduce((a, c) => { return new ListNode(c, a) }, undefined)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var mergeNodes = function (head) {
    if (!head?.next) return

    let sigma = 0
    let node = head
    do {
        sigma += node?.val || 0
        node = node?.next
    } while (node?.val)

    return node ? new ListNode(sigma, mergeNodes(node)) : new ListNode(sigma)
};

export { mergeNodes }

// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
console.log("$#",
    mergeNodes(LikedListFromAray([0, 3, 1, 0, 4, 5, 2, 0])),
    [4, 11],
    // JSON.stringify(
    LikedListFromAray([0, 3, 1, 0, 4, 5, 2, 0])
    // )
);

// Input: head = [0,1,0,3,0,2,2,0]
// Output: [1,3,4]
console.log("$#",
    mergeNodes(LikedListFromAray([0, 1, 0, 3, 0, 2, 2, 0])),
    [1, 3, 4],
    // JSON.stringify(
    LikedListFromAray([0, 1, 0, 3, 0, 2, 2, 0])
    // )
);
