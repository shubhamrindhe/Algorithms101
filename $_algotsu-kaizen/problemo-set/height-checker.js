
/**
 * 1051. Height Checker
 * https://leetcode.com/problems/height-checker/description/
 */

/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function (heights) {
    // Counting Sort...
    let maxHeight = 0
    let heightFrequencyMap = new Map()

    for (let height of heights) {
        let frequency = (heightFrequencyMap.get(height) || 0) + 1
        heightFrequencyMap.set(height, frequency)
        if (maxHeight < height) maxHeight = height
    }

    const frequencyArray = new Array(maxHeight + 1)
    // for (let [height, frequency] of heightFrequencyMap.entries()) frequencyArray[height] = frequency
    for (let idx = 0; idx < frequencyArray.length; ++idx) frequencyArray[idx] = heightFrequencyMap.get(idx) || 0

    // curried function - https://stackoverflow.com/questions/32782922/, https://stackoverflow.com/questions/20477177/
    const cumulativeSum = (sum => value => sum += value || 0)(0)
    let countArray = frequencyArray.map(cumulativeSum)

    // Sort...
    const inputArray = heights
    const outputArray = new Array(heights.length)

    let misplacedCount = 0
    for (let idx = heights.length - 1; idx >= 0; idx--) {
        // outputArray[countArray[inputArray[idx]] - 1] = inputArray[idx]
        // countArray[inputArray[idx]] = countArray[inputArray[idx]] - 1

        const idx_val = inputArray[idx]
        const out_idx = countArray[idx_val] - 1
        outputArray[out_idx] = idx_val
        countArray[idx_val] = countArray[idx_val] - 1

        if (inputArray[out_idx] != outputArray[out_idx]) {
            misplacedCount++
        }
    }

    // console.log(inputArray);
    // console.log(outputArray);

    return misplacedCount
}

export { heightChecker }

console.log(" $#", heightChecker([1, 1, 4, 2, 1, 3]))
console.log(" $#", heightChecker([5, 1, 2, 3, 4]))
console.log(" $#", heightChecker([1, 2, 3, 4, 5]))
