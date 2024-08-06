/**
 * 3016. Minimum Number of Pushes to Type Word II
 * https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
 */

/**
 * @param {string} word
 * @return {number}
 */
var minimumPushes = function (word) {
    let frequencyMap = new Map(), count = 0, i = 1
    for (const char of word) frequencyMap.set(char, (frequencyMap.get(char) || 0) + 1)
    for (const [, f] of [...frequencyMap.entries()].sort(([, f1], [, f2]) => f2 - f1))
         count += Math.ceil(i++ / 8) * f
    return count
};

export { minimumPushes }

// Input: word = "abcde"
// Output: 5
console.log("$#",
    minimumPushes(
        "abcde"
    ),
    5
);

// Input: word = "xyzxyzxyzxyz"
// Output: 12
console.log("$#",
    minimumPushes(
        "xyzxyzxyzxyz"
    ),
    12
);

// Input: word = "aabbccddeeffgghhiiiiii"
// Output: 24
console.log("$#",
    minimumPushes(
        "aabbccddeeffgghhiiiiii"
    ),
    24
);
