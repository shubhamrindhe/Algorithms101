/**
 * 1550. Three Consecutive Odds
 * https://leetcode.com/problems/three-consecutive-odds/description/
 */

const streakCheck = (list, count, check) => {
    let streak = 0
    for (const item of list) {
        if (check(item)) {
            if (++streak >= count) return true
        } else {
            streak = 0
        }
    }

    return false
}

/**
 * @param {number[]} arr
 * @return {boolean}
 */
const threeConsecutiveOdds = (arr) => {
    // return streakCheck(arr, 3, (_) => { return _ % 2 })

    if (arr.length < 3) return false
    const flags = [false, false, false]
    for (let idx = 0; idx < arr.length; idx += 3) {
        if (arr[idx] % 2) {
            if (flags[1] && flags[2]) return true
            flags[0] = true
        } else {
            flags[0] = false
        }

        if (arr[idx + 1] % 2) {
            if (flags[0] && flags[2]) return true
            flags[1] = true
        } else {
            flags[1] = false
        }

        if (arr[idx + 2] % 2) {
            if (flags[0] && flags[1]) return true
            flags[2] = true
        } else {
            flags[2] = false
        }
    }

    return false
};

export { threeConsecutiveOdds }

// Input: arr = [2,6,4,1]
// Output: false
console.log("$#", threeConsecutiveOdds([2, 6, 4, 1]), false)

// Input: arr = [1,2,34,3,4,5,7,23,12]
// Output: true
console.log("$#", threeConsecutiveOdds([1, 2, 34, 3, 4, 5, 7, 23, 12]), true)
