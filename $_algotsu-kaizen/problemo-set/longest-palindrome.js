/**
 * 409. Longest Palindrome
 * https://leetcode.com/problems/longest-palindrome/description/
 */

/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
    let evenCharCountMap = new Map()
    let oddCharCountSet = new Set()

    for (let i = 0; i < s.length; ++i) {
        let char = s.charAt(i)
        if ( oddCharCountSet.has(char) ) {
            oddCharCountSet.delete(char)
            let oldVal = evenCharCountMap.get(char) || 0
            evenCharCountMap.set(char, oldVal + 2)
        } else {
            oddCharCountSet.add(char)
        }
    }

    let longestPalindrome_len = 0
    for (let [key, value] of evenCharCountMap) longestPalindrome_len = longestPalindrome_len + value
    if (oddCharCountSet.size > 0) longestPalindrome_len = longestPalindrome_len + 1

    return longestPalindrome_len
};

export { longestPalindrome }

console.log("$#", longestPalindrome('abccccdd'));
