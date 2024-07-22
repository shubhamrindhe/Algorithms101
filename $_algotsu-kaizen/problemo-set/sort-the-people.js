/**
 * 2418. Sort the People
 * https://leetcode.com/problems/sort-the-people/description/
 */

/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function (names, heights) {
    const idx_map = new Map(heights.map((e, i) => [e, i]))
    return heights.sort((a, b) => b - a).map(e => names[idx_map.get(e)])
};

export { sortPeople }

// Input: names = ["Mary", "John", "Emma"], heights = [180, 165, 170]
// Output: ["Mary", "Emma", "John"]
console.log("$#",
    sortPeople(
        ["Mary", "John", "Emma"], [180, 165, 170]
    ),
    ["Mary", "Emma", "John"]
);

// Input: names = ["Alice", "Bob", "Bob"], heights = [155, 185, 150]
// Output: ["Bob", "Alice", "Bob"]
console.log("$#",
    sortPeople(
        ["Alice", "Bob", "Bob"], [155, 185, 150]
    ),
    ["Bob", "Alice", "Bob"]
);
