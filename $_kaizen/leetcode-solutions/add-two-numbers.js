/**
 * 2. Add Two Numbers
 * https://leetcode.com/problems/add-two-numbers/description/
 */

/**
 * Definition for singly-linked list.
 * 
*/
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
    let l1_ = l1
    let l2_ = l2
    let ouput = null
    let ouput_ = null

    let sum = 0
    let remainder = 0
    let carrie = 0

    while (Boolean(l1_) || Boolean(l2_) || Boolean(carrie)) {
        sum = (l1_?.val || 0) + (l2_?.val || 0) + carrie
        remainder = sum % 10
        carrie = (sum - remainder) / 10

        if (!ouput_) {
            ouput = new ListNode(remainder)
            ouput_ = ouput
        } else {
            ouput_.next = new ListNode(remainder)
            ouput_ = ouput_.next
        }

        l1_ = l1_?.next
        l2_ = l2_?.next
    }

    return ouput
}

export { addTwoNumbers }

let testCase1 = new ListNode(
    2,
    new ListNode(
        4,
        new ListNode(3)
    )
)

let testCase2 = new ListNode(
    5,
    new ListNode(
        6,
        new ListNode(4)
    )
)

console.log(testCase1, testCase2);
console.log("$#", addTwoNumbers(testCase1, testCase2))
