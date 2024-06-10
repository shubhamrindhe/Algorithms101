/**
 * 523. Continuous Subarray Sum
 * https://leetcode.com/problems/continuous-subarray-sum/
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum_ = function (nums, k) {
    if (nums.length < 2) return false

    let sums = new Array(nums.length)
    let sum = 0
    let ki = 0
    let flag_ = false

    let zeroFlag = false
    nums.forEach((e, i, l) => {
        sum += e
        sums[i] = sum
        if (ki == 0 && sum >= k) ki = i
        if (sum != 0 && i > 0 && sum % k == 0) {
            flag_ = true
        }

        if (i > 0 && e == 0 && l[i - 1] == 0 && !zeroFlag) {
            zeroFlag = true
        }
    })

    if (sum == 0) return true
    if (zeroFlag) return true
    if (sum > 0 && sum < k) return false
    if (flag_) return true

    for (let i = 0; i < sums.length - 1; ++i) {
        for (let j = i + 1; j < sums.length; ++j) {
            if (i == j - 1) continue
            let _sum_ = sums[j] - sums[i]
            if (_sum_ % k == 0) {
                return true
            }
        }
    }

    return flag_
};

var checkSubarraySum = function (nums, k) {
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
}

export { checkSubarraySum }

console.log("$#", checkSubarraySum([23, 2, 4, 6, 7], 6))
// console.log("$#", checkSubarraySum([23, 2, 4, 6, 7], 60))
// console.log("$#", checkSubarraySum([23, 2, 6, 4, 7], 13))
// console.log("$#", checkSubarraySum([5,0,0,0], 3))
// console.log("$#", checkSubarraySum([0], 1))
// console.log("$#", checkSubarraySum([1, 0], 2))
// console.log("$#", checkSubarraySum([1, 2, 12], 6))
// console.log("$#", checkSubarraySum([0, 1, 0, 3, 0, 4, 0, 4, 0], 5))
// console.log("$#", checkSubarraySum([5,2,4], 5))
