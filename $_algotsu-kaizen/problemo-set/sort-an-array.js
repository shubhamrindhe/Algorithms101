/**
 * 912. Sort an Array
 * https://leetcode.com/problems/sort-an-array/description/
 */

// class BinarySearchTree {

//     constructor({ val, left, right }) {
//         this.val = val
//         this.left = left
//         this.right = right
//     }

//     insert(value) {
//         this.val > value
//             ? this.left?.insert(value)
//             : this.right?.insert(value)
//     }
// }

const merge = (arr, s, m, e) => {
    const n1 = m - s + 1
    const n2 = e - m
    const arr1 = new Array(n1), arr2 = new Array(n2)
    for (let _ = 0; _ < n1; ++_) arr1[_] = arr[s + _]
    for (let _ = 0; _ < n2; ++_) arr2[_] = arr[m + 1 + _]

    let l = 0, r = 0, ptr = s
    while (l < n1 && r < n2) arr[ptr++] = arr1[l] <= arr2[r] ? arr1[l++] : arr2[r++]
    while (l < n1) arr[ptr++] = arr1[l++]
    while (r < n2) arr[ptr++] = arr2[r++]
}

const mergeSort = (arr, s, e) => {
    if (s < e) {
        const m = s + Math.floor((e - s) / 2)
        mergeSort(arr, s, m)
        mergeSort(arr, m + 1, e)
        merge(arr, s, m, e)
    }
}

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function (nums) {
    mergeSort(nums, 0, nums.length - 1)
    return nums
};

export { sortArray }

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
console.log("$#",
    sortArray(
        [5, 2, 3, 1]
    ),
    [1, 2, 3, 5]
);

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
console.log("$#",
    sortArray(
        [5, 1, 1, 2, 0, 0]
    ),
    [0, 0, 1, 1, 2, 5]
);
