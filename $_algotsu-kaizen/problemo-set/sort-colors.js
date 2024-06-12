
/**
 * 75. Sort Colors
 * https://leetcode.com/problems/sort-colors/description/
 */

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function (nums) {
    let frequencyList = [0, 0, 0]
    for (let element of nums) ++frequencyList[element]

    let idx = 0
    for (let [value, frequency] of frequencyList.entries())
        while (frequency-- > 0) nums[idx++] = value
}

export { sortColors }

console.log(" $#", sortColors([2, 0, 2, 1, 1, 0]))
console.log(" $#", [0, 0, 1, 1, 2, 2])

console.log(" $#", sortColors([2, 0, 1]))
console.log(" $#", [0, 1, 2])
