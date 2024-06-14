
/**
 * 945. Minimum Increment to Make Array Unique
 * https://leetcode.com/problems/git /description/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var minIncrementForUnique = function (nums) {
    let frequencyMap = new Map()
    let max = -Infinity, min = Infinity

    for (let num of nums) {
        let frequency = (frequencyMap.get(num) || 0) + 1
        frequencyMap.set(num, frequency)
        if (max < num) max = num
        if (min > num) min = num
    }

    let inc = 0
    for (let i = min; i <= max; ++i) {
        let inc_needed = 0
        const i_count = frequencyMap.get(i) || 0
        const i_plus_1_count = frequencyMap.get(i + 1) || 0

        if (i_count > 1) {
            frequencyMap.set(i, 1)
            inc_needed = i_count - 1
            inc += inc_needed

            frequencyMap.set(i + 1, i_plus_1_count + inc_needed)
        }
    }

    let max_frequency = frequencyMap.get(max) || 0
    let max_plus_one_frequency = frequencyMap.get(max + 1) || 0

    let i = max_frequency > 1 ? max : max + 1
    let final_inc = 0

    while (true) {
        let i_count = frequencyMap.get(i) || 0
        if (i_count <= 1) break

        if (i_count > 1) {
            frequencyMap.set(i, 1)
            let i_plus_1_count = frequencyMap.get(i + 1) || 0
            const inc_needed = i_count - 1
            final_inc += inc_needed
            frequencyMap.set(i + 1, i_plus_1_count + inc_needed)
        }

        ++i
    }


    console.log(frequencyMap, max_frequency, max_plus_one_frequency, inc)

   

    // final_inc += max_frequency > 1 ? max_frequency - 1 : 0
    // final_inc += max_plus_one_frequency > 1 ? max_plus_one_frequency - 1 : 0

    return inc + final_inc
};

export { minIncrementForUnique }

console.log(" $#", minIncrementForUnique(
    [1, 2, 2]
), 1)
// Input: nums = [1,2,2]
// Output: 1

console.log(" $#", minIncrementForUnique(
    [3, 2, 1, 2, 1, 7]
), 6)
// Input: nums = [3,2,1,2,1,7]
// Output: 6

console.log(" $#", minIncrementForUnique(
    [2, 2, 2, 2, 0]
), 6)
