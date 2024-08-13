/**
 * 40. Combination Sum II
 * https://leetcode.com/problems/combination-sum-ii/description/
 */

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
  const solution = (nums, idx, sum, accumulator, solutions) => {
    if (sum == target) {
      solutions.push([...accumulator]);
      return;
    }

    if (sum > target || idx >= nums.length) return;

    accumulator.push(nums[idx]);
    solution(nums, idx + 1, sum + nums[idx], accumulator, solutions);
    accumulator.pop();

    while (idx + 1 < nums.length && nums[idx] == nums[idx + 1]) idx++;

    solution(nums, idx + 1, sum, accumulator, solutions);
  };

  const output = [];
  solution(
    candidates.sort((a, b) => a - b),
    0,
    0,
    [],
    output
  );

  return output;
};

export { combinationSum2 };

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
console.log("$#", combinationSum2([10, 1, 2, 7, 6, 1, 5], 8), [
  [1, 1, 6],
  [1, 2, 5],
  [1, 7],
  [2, 6],
]);

// Input: candidates = [2,5,2,1,2], target = 5
// Output: [[1, 2, 2], [5]];
console.log("$#", combinationSum2([2, 5, 2, 1, 2], 5), [[1, 2, 2], [5]]);
