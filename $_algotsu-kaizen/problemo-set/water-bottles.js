/**
 * 1518. Water Bottles
 * https://leetcode.com/problems/water-bottles/description/
 */

/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function (numBottles, numExchange) {
    let drinkCount = 0
    let emptyBottles = 0
    let filledBottles = numBottles

    do {
        // # DRINK
        drinkCount += filledBottles
        emptyBottles += filledBottles
        filledBottles = 0

        // # EXCHANGE
        filledBottles = Math.floor(emptyBottles / numExchange)
        emptyBottles = emptyBottles % numExchange

    } while ((emptyBottles + filledBottles >= numExchange) || (filledBottles > 0))

    return drinkCount
};

export { numWaterBottles }

// console.log("DRINK",
//     `drinkCount ${drinkCount}`,
//     `emptyBottles ${emptyBottles}`,
//     `filledBottles ${filledBottles}`);

// console.log("EXCHANGE",
//     `emptyBottles ${emptyBottles}`,
//     `filledBottles ${filledBottles}`);

// Input: numBottles = 9, numExchange = 3
// Output: 13
console.log("$#",
    numWaterBottles(9, 3),
    13,
);

// Input: numBottles = 15, numExchange = 4
// Output: 19
console.log("$#",
    numWaterBottles(15, 4),
    19,
);
