
/**
 * 633. Sum of Square Numbers
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 */

/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function (c) {
    let left = 0, right = Math.ceil(Math.sqrt(c))
    while (left <= right) {
        const sigma = (left * left) + (right * right)
        if (sigma > c) {
            right--
        } else if (sigma < c) {
            left++
        } else {
            return true
        }
    }

    return false
};

export { judgeSquareSum }

console.log(" $#", judgeSquareSum(5), true)
console.log(" $#", judgeSquareSum(3), false)
