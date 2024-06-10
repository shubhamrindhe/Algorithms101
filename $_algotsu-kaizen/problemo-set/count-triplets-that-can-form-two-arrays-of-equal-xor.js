/**
 * 1442. Count Triplets That Can Form Two Arrays of Equal XOR
 * https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
 */

/**
 * @param {number[]} arr
 * @return {number}
 */
var countTriplets = function (arr) {
    let count = 0
    // let i = 0, j = 1, k = arr.length - 1 
    for (let i = 0; i < arr.length; ++i) {
        for (let j = i + 1; j < arr.length; ++j) {
            for (let k = j; k < arr.length; ++k) {
                let a = 0, b = 0

                for (let x = i; x < j; x++) {
                    a ^= arr[x];
                }
 
                for (let x = j; x <= k; x++) {
                    b ^= arr[x];
                }
 
                if (a == b) count++
            }
        }
    }

    return count
};

export { countTriplets }

console.log("$#", countTriplets([2, 3, 1, 6, 7]));
console.log("$#", countTriplets([1, 1, 1, 1, 1]));
