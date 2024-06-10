/**
 * 1. Two Sum
 * https://leetcode.com/problems/two-sum/description/
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const set = new Set()
    for (var i = 0; i < nums.length; ++i) {
        const n = nums[i]
        if (set.has(n)) return [n, target - n]
        set.add(target - n)
    }
};

var twoSum_BRUTEFORCE = function(nums, target) {
    var i1 = 0, i2 = 0;
    for (var i = 0; i<nums.length; ++i) {
        for (var j = i + 1; j<nums.length; ++j) {
            if (nums[i] + nums[j] == target) {
                return [i, j];
            }
        }
    }
};

export { twoSum }

console.log("$#", twoSum([2, 7, 11, 15], 9))
console.log("$#", twoSum([3, 2, 4], 6))
