/**
 * 1598. Crawler Log Folder
 * https://leetcode.com/problems/crawler-log-folder/description/
 */

/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function (logs) {
    /* # Beats 28.93% */
    // return logs.reduce((_, cmd) => { return cmd == '../' ? ( _ > 0 ? _ - 1 : _) : ( cmd == './' ? _ : _ + 1 ) }, 0)

    let wdir_depth = 0

    /* # BEATS 85% */
    logs.forEach(cmd => {
        wdir_depth = cmd == '../' 
        ? ( wdir_depth > 0 ? wdir_depth - 1 : wdir_depth)
        : ( cmd == './' ? wdir_depth : wdir_depth + 1 )
    })

    /* # BEATS 39% */
    // for (const cmd of logs) {
    //     switch (cmd) {
    //         case '../':
    //             if (wdir_depth > 0) --wdir_depth
    //             break
    //         case './':
    //             break
    //         default:
    //             ++wdir_depth
    //             break
    //     }
    // }

    return wdir_depth
};

export { minOperations }

// Input: logs = ["d1/","d2/","../","d21/","./"]
// Output: 2
console.log("$#",
    minOperations(["d1/", "d2/", "../", "d21/", "./"]),
    2,
);

// Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
// Output: 3
console.log("$#",
    minOperations(["d1/", "d2/", "./", "d3/", "../", "d31/"]),
    3,
);

// Input: logs = ["d1/","../","../","../"]
// Output: 0
console.log("$#",
    minOperations(["d1/", "../", "../", "../"]),
    0,
);
