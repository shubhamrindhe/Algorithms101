/**
 * 1636. Sort Array by Increasing Frequency
 * https://leetcode.com/problems/sort-array-by-increasing-frequency/description/
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var frequencySort = function (nums) {
    const frequencyMap = new Map()
    nums.forEach(n => frequencyMap.set(n, (frequencyMap.get(n) || 0) + 1))
    // nums.reduce((map, n) => map.set(n, (map.get(n) || 0) + 1), new Map())
    // const data = [...frequencyMap.entries()].sort(([n1, f1], [n2, f2]) => f1 == f2 ? n2 - n1 : f1 - f2)
    // let output = new Array(nums.length), idx = 0
    // for (let [n, f] of data) while(f--) output[idx++] = n
    // return output

    return nums.sort((a, b) => frequencyMap.get(a) - frequencyMap.get(b) || b - a)
};

export { frequencySort }

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
console.log("$#",
    frequencySort(
        [1, 1, 2, 2, 2, 3]
    ),
    [3, 1, 1, 2, 2, 2]
);

// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
console.log("$#",
    frequencySort(
        [2, 3, 1, 3, 2]
    ),
    [1, 3, 3, 2, 2]
);

// Input: nums = [5,-1,4,4,-6,-6,1,1,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]
console.log("$#",
    frequencySort(
        [5, -1, 4, 4, -6, -6, 1, 1, 1]
    ),
    [5, -1, 4, 4, -6, -6, 1, 1, 1]
);
