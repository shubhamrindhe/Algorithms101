/**
 * 9. Palindrome Number
 * https://leetcode.com/problems/palindrome-number/description/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var specialArray = function (nums) {
    const idx_arr = new Array(nums.length)
    let max = 0
    nums.forEach((e, i, l) => {
        for (let idx = 1; idx <= e; ++idx) {
            if (idx_arr[idx] === undefined) idx_arr[idx] = 0
            ++idx_arr[idx]
        }
        max = Math.max(max, e)
    })

    for (let idx = 1; idx <= max; ++idx) if (idx == idx_arr[idx]) return idx
    return -1
};

export { specialArray }

console.log("$#", specialArray([0, 0, 0]));
console.log("$#", specialArray([3, 5]));
console.log("$#", specialArray([0, 4, 3, 0, 4]));