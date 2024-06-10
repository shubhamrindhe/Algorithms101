/**
 * 974. Subarray Sums Divisible by K
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/description
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
const subarraysDivByK = function (nums, k) {
    let remainderIdxMap = new Map()
    remainderIdxMap.set(0, -1)
    let sum = 0

    for (let i = 0; i < nums.length; ++i) {
        sum += nums[i]
        let remainder = sum % k

        if (remainderIdxMap.has(remainder)) {
            if (i - remainderIdxMap.get(remainder) >= 2) return true
        } else {
            remainderIdxMap.set(remainder, i);
        }
    }
  
    return false;
};

export { subarraysDivByK }

console.log("$#", subarraysDivByK([4, 5, 0, -2, -3, 1], 5));
