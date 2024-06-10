/**
 * 344. Reverse String
 * https://leetcode.com/problems/reverse-string/description/
 */

/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
const reverseString = function(s) {
    let l = 0, r = s.length - 1
    while (l < r) {
        let l_char = s[l]
        let r_char = s[r]
        s[l++] = r_char
        s[r--] = l_char
    }
};

export { reverseString }

console.log(" $#", reverseString(["h", "e", "l", "l", "o"]))
