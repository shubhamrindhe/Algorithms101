/**
 * 624. Maximum Distance in Arrays
 * https://leetcode.com/problems/maximum-distance-in-arrays/description/
 */

/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function (arrays) {
  let min = Infinity,
    max = -Infinity,
    kai = 0;

  // for (const arr of arrays) {
  //     const hasMin = min > arr[0]
  //     const hasMax = max < arr[arr.length - 1]

  //     if (hasMin && hasMax && min != Infinity && max != -Infinity) {
  //       if (max - arr[0] > arr[arr.length - 1] - min) {
  //         min = arr[0]
  //       } else {
  //         max = arr[arr.length - 1]
  //       }

  //       console.log(arr, min, max);
  //       continue
  //     }

  //     if (hasMin) min = arr[0]
  //     if (hasMax) max = arr[arr.length - 1]
  //     console.log(arr, min, max);
  // }

  // return max - min

  for (const arr of arrays) {
    // console.log(kai, arr[arr.length - 1] - min, max - arr[0]);
    kai = Math.max(kai, arr[arr.length - 1] - min, max - arr[0]);
    min = Math.min(min, arr[0])
    max = Math.max(max, arr[arr.length - 1]);
  }

  return kai;
};

export { maxDistance };

// Input: arrays = [[1,2,3],[4,5],[1,2,3]]
// Output: 4
console.log(
  "$#",
  maxDistance([
    [1, 2, 3],
    [4, 5],
    [1, 2, 3],
  ]),
  4
);

// Input: arrays = [[1],[1]]
// Output: 0
console.log("$#", maxDistance([[1], [1]]), 0);

// Input: arrays = [[1,5],[3,4]]
// Output: 0
console.log(
  "$#",
  maxDistance([
    [1, 5],
    [3, 4],
  ]),
  3
);
