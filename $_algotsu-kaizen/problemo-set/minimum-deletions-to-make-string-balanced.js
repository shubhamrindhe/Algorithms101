/**
 * 1653. Minimum Deletions to Make String Balanced
 * https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/
 */

/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function (string) {
    let d_count = 0, b_count = 0
    for (let char of string) {
        if (char == 'b') {
            b_count++
            continue
        }

        b_count > 0 && ++d_count && --b_count
    }

    return d_count
};

export { minimumDeletions }

// Input: s = "aababbab"
// Output: 2
console.log("$#",
    minimumDeletions(
        "aababbab"
    ),
    2
);

// Input: s = "bbaaaaabb"
// Output: 2
console.log("$#",
    minimumDeletions(
        "bbaaaaabb"
    ),
    2
);
