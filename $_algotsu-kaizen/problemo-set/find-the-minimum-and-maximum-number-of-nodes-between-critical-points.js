/**
 * 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
 * https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
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
 * @return {number[]}
 */
var nodesBetweenCriticalPoints = function (head) {
    let minDistance = Infinity, maxDistance = -Infinity
    let idx = 0, traveller = head, shadow = null
    let superposition_one = null, superposition_last = null

    while (traveller) {
        if (shadow && traveller.next) {
            const local_minima = (traveller.val < shadow.val && traveller.val < traveller.next.val)
            const local_maxima = (traveller.val > shadow.val && traveller.val > traveller.next.val)

            if (local_minima || local_maxima) {
                if (superposition_one) {
                    maxDistance = Math.max(maxDistance, idx - superposition_one)
                } else {
                    superposition_one = idx
                }

                if (superposition_last) {
                    minDistance = Math.min(minDistance, idx - superposition_last)
                }

                superposition_last = idx
            }
        }

        shadow = traveller
        traveller = traveller.next
        idx++
    }

    return superposition_last > superposition_one ? [minDistance, maxDistance] : [-1, -1]
};

export { nodesBetweenCriticalPoints }

// Example 1:
// Input: head = [3,1]
// Output: [-1,-1]
console.log("$#",
    nodesBetweenCriticalPoints(LikedListFromAray([3, 1])).toString(),
    "  ==  ",
    [-1, -1].toString(),
    // JSON.stringify(
    // LikedListFromAray([0, 1, 0, 3, 0, 2, 2, 0])
    // )
);

// Example 2:
// Input: head = [5,3,1,2,5,1,2]
// Output: [1,3]
console.log("$#",
    nodesBetweenCriticalPoints(LikedListFromAray([5, 3, 1, 2, 5, 1, 2])).toString(),
    "  ==  ",
    [1, 3].toString(),
    // JSON.stringify(
    LikedListFromAray([5, 3, 1, 2, 5, 1, 2])
    // )
);

// Example 3:
// Input: head = [1,3,2,2,3,2,2,2,7]
// Output: [3,3]
console.log("$#",
    nodesBetweenCriticalPoints(LikedListFromAray([1, 3, 2, 2, 3, 2, 2, 2, 7])).toString(),
    "  ==  ",
    [3, 3].toString(),
    // JSON.stringify(
    // LikedListFromAray([0, 1, 0, 3, 0, 2, 2, 0])
    // )
);
