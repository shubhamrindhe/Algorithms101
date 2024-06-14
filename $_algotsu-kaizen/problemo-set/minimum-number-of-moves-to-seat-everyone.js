
/**
 * 2037. Minimum Number of Moves to Seat Everyone
 * https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
 */

/**
 * @param {number[]} seats
 * @param {number[]} students
 * @return {number}
 */
var minMovesToSeat = function (seats, students) {
    const sorted_seats = seats.sort((a, b) => { return a - b })
    const sorted_students = students.sort((a, b) => { return a - b })

    let move_count = 0
    for (let idx = 0; idx < sorted_seats.length; ++idx) move_count += Math.abs(sorted_seats[idx] - sorted_students[idx])

    return move_count
};

export { minMovesToSeat }

// Input: seats = [3,1,5], students = [2,7,4]
// Output: 4
console.log(" $#", minMovesToSeat([3, 1, 5], [2, 7, 4]))
console.log(" $#", 4)

// Input: seats = [4,1,5,9], students = [1,3,2,6]
// Output: 7
console.log(" $#", minMovesToSeat([4, 1, 5, 9], [1, 3, 2, 6]))
console.log(" $#", 7)

// Input: seats = [2,2,6,6], students = [1,3,2,6]
// Output: 4
console.log(" $#", minMovesToSeat([2, 2, 6, 6], [1, 3, 2, 6]))
console.log(" $#", 4)