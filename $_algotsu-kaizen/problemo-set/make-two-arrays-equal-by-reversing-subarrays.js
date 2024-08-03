/**
 * 1460. Make Two Arrays Equal by Reversing Subarrays
 * https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/
 */

/**
 * @param {number[]} target
 * @param {number[]} arr
 * @return {boolean}
 */
var canBeEqual = function (target, arr) {
    let fmap = new Map()
    target.forEach(e => fmap.set(e, (fmap.get(e) || 0) + 1))

    for (const e of arr) {
        const f = fmap.get(e)
        if (!f) return false
        f == 1 ? fmap.delete(e) : fmap.set(e, f - 1)
    }

    return fmap.size == 0
};

export { canBeEqual }

// Input: target = [1,2,3,4], arr = [2,4,1,3]
// Output: true
console.log("$#",
    canBeEqual(
        [1, 2, 3, 4], [2, 4, 1, 3],
    ),
    true
);

// Input: target = [7], arr = [7]
// Output: true
console.log("$#",
    canBeEqual(
        [7], [7],
    ),
    true
);

// Input: target = [3,7,9], arr = [3,7,11]
// Output: false
console.log("$#",
    canBeEqual(
        [3, 7, 9], [3, 7, 11],
    ),
    false
);
