/**
 * 1701. Average Waiting Time
 * https://leetcode.com/problems/average-waiting-time/description/
 */

/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function (customers) {
    let totalTimeWaited = 0
    let chefOccupiedTillTime = 0

    for (const [arrivalTime, orderTime] of customers) {
        if (chefOccupiedTillTime <= arrivalTime) {
            totalTimeWaited += orderTime
            chefOccupiedTillTime = arrivalTime + orderTime
        } else {
            totalTimeWaited += orderTime + (chefOccupiedTillTime - arrivalTime)
            chefOccupiedTillTime += orderTime
        }
    }

    return totalTimeWaited / customers.length
};

export { averageWaitingTime }

// Input: customers = [[1,2],[2,5],[4,3]]
// Output: 5.00000
console.log("$#",
    averageWaitingTime([[1, 2], [2, 5], [4, 3]]),
    5,
);

// Input: customers = [[5,2],[5,4],[10,3],[20,1]]
// Output: 3.25000
console.log("$#",
    averageWaitingTime([[5, 2], [5, 4], [10, 3], [20, 1]]),
    3.25,
);
