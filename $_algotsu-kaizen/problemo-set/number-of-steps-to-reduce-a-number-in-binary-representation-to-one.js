/**
 * 1404. Number of Steps to Reduce a Number in Binary Representation to One
 * https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/
 */

/**
 * @param {string} s
 * @return {number}
 */
var numSteps = function(s) {
    let steps = 0

    /* // Dumb Shit
    let n = parseInt(s, 2)
    while (n != 1) {
        let _ = (n % 2) ? n += 1 : n /= 2 
        ++steps
    }
    */

    let str = new String(s)
    let arr = str.split('')
    let pointer = str.length - 1
    while (pointer > 0) {
        let char = arr[pointer]
        if (char == '1') {
            ++steps
            while (pointer > 0 && arr[pointer] == '1') { 
                ++steps
                --pointer
             }

             if (pointer == 0) ++steps

             arr[pointer] = '1'
        } else {
            ++steps
            --pointer            
        }
    }

    return steps
};

export { numSteps }

console.log("$#", numSteps("1101"));
