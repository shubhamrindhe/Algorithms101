/**
 * 264. Ugly Number II
 * https://leetcode.com/problems/ugly-number-ii/description/
 */

/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function (n) {
    // const uglySet = new Set([1])
    // const queue = [2, 3, 5]
    // while(uglySet.size < n) {

    // }

    let idx2 = 0b0
    let idx3 = 0b0
    let idx5 = 0b0

    let uglyList = [0b1]

    do {
        const m2 = uglyList[idx2] * 0x2
        const m3 = uglyList[idx3] * 0x3
        const m5 = uglyList[idx5] * 0x5
        const nextMin = Math.min(m2, m3, m5)
        uglyList.push(nextMin)

        nextMin == m2 && idx2++
        nextMin == m3 && idx3++
        nextMin == m5 && idx5++
    } while (uglyList.length < n)
    
    return uglyList[n-1]  
};

export { nthUglyNumber };

// Input: n = 10
// Output: 12
console.log(
    "$#",
    nthUglyNumber(10),
    12
)

// Input: n = 1
// Output: 1
console.log(
    "$#",
    nthUglyNumber(1),
    1
)
