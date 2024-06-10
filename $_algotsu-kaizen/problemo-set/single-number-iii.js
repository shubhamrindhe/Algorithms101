/**
 * 260. Single Number III
 * https://leetcode.com/problems/single-number-iii/description/
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function (nums) {
    // Dumb Shit
    // let set = new Set()
    // nums.forEach(e => { set.has(e) ? set.delete(e) : set.add(e) })
    // return Array.from(set)

    let xor = 0
    nums.forEach(e => { xor ^= e })

    let kai_bit = 1
    while (!(xor & kai_bit)) kai_bit = kai_bit << 1

    console.log(kai_bit);

    let one = 0, two = 0
    nums.forEach(e => {
        if (kai_bit & e)
            one = one ^ e
        else
            two = two ^ e
    })

    return [one, two]
};

export { singleNumber }

console.log("$#", singleNumber([1, 2, 1, 3, 2, 5]))
