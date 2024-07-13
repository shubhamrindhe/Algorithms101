/**
 * 2751. Robot Collisions
 * https://leetcode.com/problems/robot-collisions/description/
 */

/**
 * @param {number[]} positions
 * @param {number[]} healths
 * @param {string} directions
 * @return {number[]}
 */
var survivedRobotsHealths = function (positions, healths, directions) {
    const positionIdxMap = new Map()
    for (let idx = 0; idx < positions.length; ++idx) positionIdxMap.set(positions[idx], idx)
    positions.sort((a, b) => { return a - b })

    let stack = []

    for (const position of positions) {
        const idx = positionIdxMap.get(position)
        const direction = directions.charAt(idx)

        if (direction == 'L') {
            let previousIDX = stack[stack.length - 1]
            if (previousIDX >= 0 && directions.charAt(previousIDX) == 'R') {
                while (previousIDX >= 0 && directions.charAt(previousIDX) == 'R') {
                    if (healths[previousIDX] < healths[idx]) {
                        stack.pop()
                        healths[previousIDX] = 0
                        healths[idx]--
                        previousIDX = stack[stack.length - 1]
                    } else if (healths[previousIDX] > healths[idx]) {
                        healths[previousIDX]--
                        healths[idx] = 0
                        previousIDX = stack[stack.length - 1]
                        break
                    } else {
                        stack.pop()
                        healths[previousIDX] = 0
                        healths[idx] = 0
                        previousIDX = stack[stack.length - 1]
                        break
                    }
                }

                if (healths[idx] > 0) {
                    stack.push(idx)
                }
            } else {
                stack.push(idx)
            }
        } else if (direction == 'R') {
            stack.push(idx)
        }
    }

    return healths.filter($ => Boolean($))
};

export { survivedRobotsHealths }

// Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
// Output: [2,17,9,15,10]
console.log("$#",
    survivedRobotsHealths([5, 4, 3, 2, 1], [2, 17, 9, 15, 10], "RRRRR"),
    [2, 17, 9, 15, 10],
);

// Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
// Output: [14]
console.log("$#",
    survivedRobotsHealths([3, 5, 2, 6], [10, 10, 15, 12], "RLRL"),
    [14],
);

// Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
// Output: []
console.log("$#",
    survivedRobotsHealths([1, 2, 5, 6], [10, 10, 11, 11], "RLRL"),
    [],
);

// Input: positions = [6,34], healths = [314,559], directions = "RL"
// Output: [558]
console.log("$#",
    survivedRobotsHealths([6, 34], [314, 559], "RL"),
    [558],
);
