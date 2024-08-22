/**
 * 476. Number Complement
 * https://leetcode.com/problems/number-complement/description/
 */

/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function (num) {
    const bit = new Uint32Array(0x1)///0b1
    bit[0x0] = 0b1
    const U_INT_0x20 = new Uint32Array(0x1)
    U_INT_0x20[0x0] = Number(num)

    while (bit <= U_INT_0x20[0x0]) {
        if (U_INT_0x20[0x0] & bit[0])
            U_INT_0x20[0x0] ^= bit[0]
        else
            U_INT_0x20[0x0] |= bit[0]
        bit[0] = bit[0] << 0b1
    }

    return U_INT_0x20[0x0]
};

export { findComplement }

// Input: nums = 5
// Output: 2
console.log("$#",
    findComplement(
        5
    ),
    2
);

// Input: nums = 1
// Output: 0
console.log("$#",
    findComplement(
        1
    ),
    0
);

// Input: nums = 2147483647
// Output: 0
console.log("$#",
    findComplement(
        2147483647
    ),
    0
);
