/**
 * 2486. Append Characters to String to Make Subsequence
 * https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/
 */

/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
const appendCharacters = function(s, t) {
    let ti = 0
    let si = 0

    while (si < s.length && ti < t.length) {
        if ( s.charAt(si) == t.charAt(ti) ) ++ti
        ++si
    }

    return t.length - ti
}

export { appendCharacters }

console.log("$#", appendCharacters("coaching", "coding"))
console.log("$#", appendCharacters("abcde", "a"))
