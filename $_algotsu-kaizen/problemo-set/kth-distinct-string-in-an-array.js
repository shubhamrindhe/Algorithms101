/**
 * 2053. Kth Distinct String in an Array
 * https://leetcode.com/problems/kth-distinct-string-in-an-array/description/
 */

/**
 * @param {string[]} arr
 * @param {number} k
 * @return {string}
 */
var kthDistinct = function (arr, k) {
    let lookupMap = new Map(), distinctKount = 0
    arr.forEach(e => lookupMap.set(e, (lookupMap.get(e) || 0) + 1) )
    for (const str of arr) if (lookupMap.get(str) == 1 && ++distinctKount == k) return str
    return ''
};

export { kthDistinct }

// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
console.log("$#",
    kthDistinct(
        ["d", "b", "c", "b", "c", "a"], 2
    ),
    'a'
);

// Input: arr = ["aaa","aa","a"], k = 1
// Output: "aaa"
console.log("$#",
    kthDistinct(
        ["aaa", "aa", "a"], 1
    ),
    'aaa'
);

// Input: arr = ["a","b","a"], k = 3
// Output: ""
console.log("$#",
    kthDistinct(
        ["a", "b", "a"], 3
    ),
    ''
);
