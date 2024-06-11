
/**
 * 1122. Relative Sort Array
 * https://leetcode.com/problems/relative-sort-array/description/
 */

/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    let prefixSet = new Set(arr2)
    let prefixFrequencyMap = new Map()
    let prefixSize = 0
    // let suffixFrequencyMap = new Map()
    // let suffixSize = 0
    let suffix_arr = []

    for (let element of arr1) {
        if (prefixSet.has(element)) {
            prefixFrequencyMap.set(element, (prefixFrequencyMap.get(element) || 0) + 1)
            ++prefixSize
        } else {
            // suffixFrequencyMap.set(element, (suffixFrequencyMap.get(element) || 0) + 1 )
            suffix_arr.push(element)
            // ++suffixSize
        }
    }

    let output_prefix = new Array(prefixSize)
    let pre_idx = 0
    for (let element of arr2) {
        let fillCount = prefixFrequencyMap.get(element)
        while (fillCount-- > 0) output_prefix[pre_idx++] = element
    }

    return output_prefix.concat(suffix_arr.sort((a,b) => { a - b }))
};

export { relativeSortArray }

console.log(" $#", relativeSortArray(
    [2,3,1,3,2,4,6,7,9,2,19], [2,1,4,3,9,6]
))

console.log(" $#", relativeSortArray(
    [2,3,1,3,2,4,6,7,9,2,19], [2,1,4,3,9,6]
).join(','))
console.log(" $#", [2,2,2,1,4,3,3,9,6,7,19].join(','))
