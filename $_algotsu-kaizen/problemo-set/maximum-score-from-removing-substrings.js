/**
 * 1717. Maximum Score From Removing Substrings
 * https://leetcode.com/problems/maximum-score-from-removing-substrings/description/
 */

/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var maximumGain = function(s, x, y) {
    const pop_all_substr = (str, substr) => {
        let stack = []
        let pops = 0

        for (const char of str) {
            if (char == substr.charAt(1) && stack.length > 0 && stack[stack.length - 1] == substr.charAt(0)) {
                stack.pop()
                ++pops
            } else {
                stack.push(char)
            }
        }

        return [stack.join(''), pops]
    }

    const [round_one_substr, round_two_substr] = x > y ? ['ab', 'ba'] : ['ba', 'ab']
    const [round_one_output, round_one_pops] = pop_all_substr(s, round_one_substr)
    const [round_two_output, round_two_pops] = pop_all_substr(round_one_output, round_two_substr)
    return (round_one_pops * Math.max(x, y)) + (round_two_pops * Math.min(x, y))
};

export { maximumGain }

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
console.log("$#",
    maximumGain("cdbcbbaaabab", 4, 5),
    19,
);

// Input: s = "aabbaaxybbaabb", x = 5, y = 4
// Output: 20
console.log("$#",
    maximumGain( "aabbaaxybbaabb", 5, 4),
    20,
);
