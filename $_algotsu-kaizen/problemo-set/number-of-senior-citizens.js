/**
 * 2678. Number of Senior Citizens
 * https://leetcode.com/problems/number-of-senior-citizens/description/
 */

/**
 * @param {string[]} details
 * @return {number}
 */
var countSeniors = function (details) {
    return details.reduce((count, e) => {
        return (e.charAt(0xB) + e.charAt(0xC)) > '60' ? count + 0x1 : count
    }, 0)
};

export { countSeniors }

// Input: details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
// Output: 2
// console.log("$#",
//     countSeniors(
//         ["7868190130M7522", "5303914400F9211", "9273338290F4010"]
//     ),
//     2
// );

// // Input: details = ["1313579440F2036","2921522980M5644"]
// // Output: 0
// console.log("$#",
//     countSeniors(
//         ["1313579440F2036", "2921522980M5644"]
//     ),
//     0
// );

// ["5612624052M0130","5378802576M6424","5447619845F0171","2941701174O9078"],
// 2
console.log("$#",
    countSeniors(
        ["5612624052M0130","5378802576M6424","5447619845F0171","2941701174O9078"]
    ),
    2
);