/**
 * 350. Intersection of Two Arrays II
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 */

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
    let countMap = new Map()

    const add = (_, idx) => {
        if (!countMap.has(_)) countMap.set(_, [0, 0])
        countMap.get(_)[idx]++
    }

    const maxLength = Math.max(nums1.length, nums2.length)
    for (let idx = 0; idx < maxLength; ++idx) {
        const n1 = nums1[idx]
        const n2 = nums2[idx]
        if (n1 !== undefined) add(n1, 0)
        if (n2 !== undefined) add(n2, 1)
    }

    const output = []
    for (const [key, values] of countMap.entries()) {
        const i = Math.min(...values)
        while (i--) output.push(key)
    }

    return output
};

export { intersect }

console.log("$#", intersect([1, 2, 2, 1], [2, 2]), [2, 2]);
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

console.log("$#", intersect([4, 9, 5], [9, 4, 9, 8, 4]), [4, 9]);
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]

console.log("$#", intersect([8, 0, 3], [0, 0]), [0]);
// [8,0,3]
// [0,0]
