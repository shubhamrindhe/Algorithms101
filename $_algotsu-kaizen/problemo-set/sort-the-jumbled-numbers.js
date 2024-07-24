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

/**
 * @param {number[]} mapping
 * @param {number[]} nums
 * @return {number[]}
 */
var sortJumbled = function (mapping, nums) {
    const n_map = new Map()
    nums.forEach(n => {
        if (!n_map.has(n)) n_map.set(n, n.toString().split('').reduce((sum, digit) => (sum * 0xA) + mapping[+digit], 0b0))
    })

    return nums.sort((a, b) => n_map.get(a) - n_map.get(b))
};

export { sortJumbled }

// Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
// Output: [338,38,991]
console.log("$#",
    sortJumbled(
        [8, 9, 4, 0, 2, 1, 3, 5, 7, 6], [991, 338, 38]
    ),
    [338, 38, 991]
);

// Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
// Output: [123,456,789]
console.log("$#",
    sortJumbled(
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [789, 456, 123]
    ),
    [123, 456, 789]
);
