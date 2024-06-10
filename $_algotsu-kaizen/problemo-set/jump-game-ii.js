/**
 * 45. Jump Game II
 * https://leetcode.com/problems/jump-game-ii/description/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = (nums, p = 0, jump_count = 0) => {
    if (p >= nums.length - 1) {
        return nums[p] ? ++jump_count : Infinity
    }

    let JC = jump_count
    for (let i = p; i < Math.min(nums[p], nums.length - 1 - p); ++i) {
        let j_c = jump(nums, i + 1, jump_count + 1)
        console.log(JC, j_c);
        JC = Math.min(JC, j_c)
    }

    return JC
}

export { jump }

console.log(" $#", jump([2, 3, 1, 1, 4]))
