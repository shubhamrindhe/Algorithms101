/**
 * 703. Kth Largest Element in a Stream
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/
 */


function Node(val, left, right) {
    this.val = val
    this.left = left
    this.right = right
}

/**
 * @param {number} k
 * @param {number[]} nums
 */
var KthLargest = function (k, nums) {
    this.k = k
    nums.sort((a, b) => b - a)
    this.slicedArray = nums.slice(0, this.k);
};

/**
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function (val) {
    this.slicedArray.push(val)
    this.slicedArray.sort((a, b) => b - a)
    this.slicedArray = this.slicedArray.slice(0, this.k);
    return this.slicedArray[this.slicedArray.length - 1]
};

export { minDays };

// Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 2
console.log(
  "$#",
  minDays([
    [0, 1, 1, 0],
    [0, 1, 1, 0],
    [0, 0, 0, 0],
  ]),
  2
);

// Input: grid = [[1,1]]
// Output: 2
console.log("$#", minDays([[1, 1]]), 2);
