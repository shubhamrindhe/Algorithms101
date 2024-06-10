/**
 * 1208. Get Equal Substrings Within Budget
 * https://leetcode.com/problems/get-equal-substrings-within-budget/description/
 */

/**
 * @param {string} s
 * @param {string} t
 * @param {number} maxCost
 * @return {number}
 */
const equalSubstring = function (s, t, maxCost) {
    let costSumList = new Array(s.length)
    let kai = new Array(s.length)
    let costSum = 0

    let map = new Map()

    for (let i = 0; i < s.length; ++i) {
        let d = Math.abs(t.charCodeAt(i) - s.charCodeAt(i))
        costSum += d
        kai[i] = d
        costSumList[i] = costSum
    }

    let max_len = 0
    for (let i = 0; i < kai.length; ++i) {
        let totalCost = 0
        for (let j = i; j < kai.length; ++j) {
        // for (let j = kai.length - 1; j >= i; ++j) {

            let length = j - i + 1

            totalCost += kai[j]

            if (totalCost <= maxCost) {
                max_len = Math.max(max_len, length)
            }
        }   
    }

    // let left = 0
    // let cost = 0 
    // for (let right = 0; right < s.length(); ++right) {
    //     cost += Math.abs(t.charCodeAt(right) - s.charCodeAt(right)) //abs(t[right] - s[right]);
    //     while (cost > maxCost) {
    //         cost -= Math.abs(t.charCodeAt(left) - s.charCodeAt(left))//abs(t[left] - s[left]);
    //         ++left;
    //     }
    //     max_len = Math.max(max_len, right - left + 1);
    // }


    return max_len
};

export { equalSubstring }

// s = "abcd", t = "bcdf", maxCost = 3
console.log("$#", equalSubstring("abcd", "bcdf", 3));

// Input: s = "abcd", t = "cdef", maxCost = 3
// Output: 1
// Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
// Example 3:

console.log("$#", equalSubstring("abcd", "cdef", 3));

console.log("$#", equalSubstring("abcd", "acde", 0));
