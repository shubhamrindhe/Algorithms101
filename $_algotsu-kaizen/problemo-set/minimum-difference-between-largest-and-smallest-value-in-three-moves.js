/**
 * 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
 * https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
const minDifference = (nums) => {
    if (nums.length <= 4) return 0
    nums.sort((a, b) => { return a - b })

    const one = nums[0],
        two = nums[1],
        three = nums[2],
        four = nums[3];
    const _one = nums[nums.length - 1],
        _two = nums[nums.length - 2],
        _three = nums[nums.length - 3],
        _four = nums[nums.length - 4];

    // 0 3 minus_four - one
    // 1 2 minus_three - two
    // 2 1 minus_two - three
    // 3 0 minus_one - four
    let output = Math.min(
        _four - one,
        _three - two,
        _two - three,
        _one - four
    )

    return output
};

export { minDifference }

console.log(" $#", minDifference(
    [5, 3, 2, 4]
), 0)
// Input: nums = [5,3,2,4]
// Output: 0

console.log(" $#", minDifference(
    [1, 5, 0, 10, 14]
), 1)
// Input: nums = [1,5,0,10,14]
// Output: 1

console.log(" $#", minDifference(
    [3, 100, 20]
), 0)
// Input: nums = [3,100,20]
// Output: 0