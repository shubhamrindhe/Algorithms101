/**
 * 3. Longest Substring Without Repeating Characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 */

const longestSubstringWithoutRepeatingCharacters = (s) => {
    if (s.length == 1) { return s }

    let charSet = new Set()
    let aux_s = new String(s)
    let current_substring = ''

    let flag = true
    let longString = ''
    for (let i = 0; i < aux_s.length; ++i) {
        let char = aux_s.charAt(i)
        if (charSet.has(char)) {
            flag = false
        }

        if (flag) {
            charSet.add(char)
            current_substring += char
        }

        if (i != 0) {
            let subs = aux_s.substring(i)
            let pls = longestSubstringWithoutRepeatingCharacters(subs)
            console.log(pls);

            if (pls.length > longString.length) {
                longString = pls
            }
        }
    }

    return current_substring.length > longString.length ? current_substring : longString
}

const lengthOfLongestSubstring = function (s) {
    let string = longestSubstringWithoutRepeatingCharacters(s)
    return string.length
};

export { lengthOfLongestSubstring }

// console.log("$#", lengthOfLongestSubstring('abcabcbb'));
// console.log("$#", lengthOfLongestSubstring('pwwkew'));

console.log("$#", lengthOfLongestSubstring('bppvuikicnhlvnsnklobqk'));
