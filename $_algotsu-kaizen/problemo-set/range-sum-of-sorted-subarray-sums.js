/**
 * 1508. Range Sum of Sorted Subarray Sums
 * https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
 */

/**
 * @param {number[]} nums
 * @param {number} n
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeSum = function (nums, n, left, right) {
    let sumarr = [], prime = Math.pow(10, 9) + 7

    for (let i = 0, s = 0; i < n; ++i, s = 0)
        for (let j = i; j < n; ++j)
            sumarr.push(s += nums[j] % prime)

    sumarr.sort((a, b) => a - b)

    let sum = 0
    for (let i = left - 1; i < right; ++i) sum += sumarr[i]

    return sum
};

export { rangeSum }

// Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
// Output: 13 
console.log("$#",
    rangeSum(
        [1, 2, 3, 4], 4, 1, 5
    ),
    "13",
);

// Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
// Output: 6
console.log("$#",
    rangeSum(
        [1, 2, 3, 4], 4, 3, 4
    ),
    "6",
);

// Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
// Output: 50
console.log("$#",
    rangeSum(
        [1, 2, 3, 4], 4, 1, 10
    ),
    "50",
);
