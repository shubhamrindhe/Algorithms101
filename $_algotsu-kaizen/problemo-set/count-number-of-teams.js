/**
 * 1395. Count Number of Teams
 * https://leetcode.com/problems/count-number-of-teams/description/
 */

/**
 * @param {number[]} rating
 * @return {number}
 */
var numTeams = function (ratings) {
    let validTeamsCount = 0

    for (let mid = 1; mid < ratings.length - 1; ++mid) {
        // let lftCount = [0, 0], rgtCount = [0, 0]
        // for (let lft = 0; lft < mid; ++lft)
        //     ++lftCount[+(ratings[lft] < ratings[mid])]
        // for (let rgt = mid + 1; rgt < ratings.length; ++rgt)
        //     ++rgtCount[+(ratings[mid] < ratings[rgt])]
        // validTeamsCount += lftCount[0] * rgtCount[0] + lftCount[1] * rgtCount[1]

        const counts = [[0, 0], [0, 0]]
        for (let idx = 0; idx < ratings.length; ++idx) {
            if (idx == mid) continue
            ++counts[+(idx < mid)][+(ratings[idx] < ratings[mid])]
        }

        validTeamsCount += counts[0][0] * counts[1][1] + counts[0][1] * counts[1][0]
    }

    return validTeamsCount
};

export { numTeams }

// Input: rating = [2,5,3,4,1]
// Output: 3
console.log("$#",
    numTeams(
        [2, 5, 3, 4, 1]
    ),
    3
);

// Input: rating = [2,1,3]
// Output: 0
console.log("$#",
    numTeams(
        [2, 1, 3]
    ),
    0
);

// Input: rating = [1,2,3,4]
// Output: 4
console.log("$#",
    numTeams(
        [1, 2, 3, 4]
    ),
    4
);
