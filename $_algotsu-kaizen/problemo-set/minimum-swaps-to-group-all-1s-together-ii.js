/**
 * 2134. Minimum Swaps to Group All 1's Together II
 * https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var minSwaps = function (nums) {
    let sum = new Array(nums.length), F1 = 0
    nums.forEach((bit, idx) => sum[idx] = F1 += bit)
    if (F1 == nums.length) return 0

    let l = 0, r = F1
    let min = Infinity
    while (l < nums.length) {
        const zeros = F1 - (r > l ? (sum[r] - sum[l++]) : ((sum[sum.length - 1] - sum[l++]) + sum[r]))
        if (zeros < min) min = zeros
        ++r >= nums.length && (r %= nums.length) // r = ++r >= nums.length ? r % nums.length : r
    }

    return min
};

export { minSwaps }

// Input: nums = [0,1,0,1,1,0,0]
// Output: 1
console.log("$#",
    minSwaps(
        [0, 1, 0, 1, 1, 0, 0]
    ),
    1
);

// Input: nums = [0,1,1,1,0,0,1,1,0]
// Output: 2
console.log("$#",
    minSwaps(
        [0, 1, 1, 1, 0, 0, 1, 1, 0]
    ),
    2
);

// Input: nums = [1,1,0,0,1]
// Output: 0
console.log("$#",
    minSwaps(
        [1, 1, 0, 0, 1]
    ),
    0
);

// Input: nums = [1]
// Output: 0
console.log("$#",
    minSwaps(
        [1]
    ),
    0
);

// Input: nums = [1, 1]
// Output: 0
console.log("$#",
    minSwaps(
        [1, 1]
    ),
    0
);
