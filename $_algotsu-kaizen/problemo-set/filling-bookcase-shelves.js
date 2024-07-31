/**
 * 1105. Filling Bookcase Shelves
 * https://leetcode.com/problems/filling-bookcase-shelves/description/
 */

/**
 * @param {number[][]} books
 * @param {number} shelfWidth
 * @return {number}
 */
var minHeightShelves = function (books, shelfWidth, idx = 0, dp = new Array(1000)) {
    if (idx == books.length) return 0
    if (dp[idx]) return dp[idx]
    let availWidth = Number(shelfWidth)
    let maxHeight = 0
    dp[idx] = Infinity
    for (let i = idx; i < books.length; ++i) {
        const [bwidth, bheight] = books[i]
        if (bwidth > availWidth) break
        availWidth -= bwidth
        maxHeight = Math.max(maxHeight, bheight)

        dp[idx] = Math.min(
            dp[idx],
            minHeightShelves(books, shelfWidth, i + 1, dp) + maxHeight
        )
    }

    return dp[idx]
};

export { minHeightShelves }

// Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
// Output: 6
console.log("$#",
    minHeightShelves(
        [[1, 1], [2, 3], [2, 3], [1, 1], [1, 1], [1, 1], [1, 2]],
        4
    ),
    6
);

// Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
// Output: 4
console.log("$#",
    minHeightShelves(
        [[1, 3], [2, 4], [3, 2]],
        6
    ),
    4
);
