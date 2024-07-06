/**
 * 2582. Pass the Pillow
 * https://leetcode.com/problems/pass-the-pillow/description/
 */

/**
 * @param {number} n
 * @param {number} time
 * @return {number}
 */
var passThePillow = function (n, time) {
    // # FORMULA
    const directionSwicthCount = Math.floor(time / (n - 1))
    const timeRemainedAfterAllDirectionSwicth = time % (n - 1)
    const directionSwitchParity = directionSwicthCount % 2
    return directionSwitchParity ? n - timeRemainedAfterAllDirectionSwicth : timeRemainedAfterAllDirectionSwicth + 1
};

export { passThePillow }

// Input: n = 4, time = 5
// Output: 2
console.log("$#",
    passThePillow(4, 5),
    2,
);

// Input: n = 3, time = 2
// Output: 3
console.log("$#",
    passThePillow(3, 2),
    3,
);

// # CUSTOM

console.log("$#",
    passThePillow(7, 5),
    6,
);
console.log("$#",
    passThePillow(7, 10),
    3,
);
console.log("$#",
    passThePillow(7, 15),
    4,
);
console.log("$#",
    passThePillow(7, 20),
    5,
);
console.log("$#",
    passThePillow(7, 25),
    2,
);
console.log("$#",
    passThePillow(7, 30),
    7,
);



console.log("$#",
    passThePillow(4, 5),
    2,
);
console.log("$#",
    passThePillow(4, 10),
    3,
);
console.log("$#",
    passThePillow(4, 15),
    4,
);
console.log("$#",
    passThePillow(4, 20),
    3,
);
console.log("$#",
    passThePillow(4, 25),
    2,
);
console.log("$#",
    passThePillow(4, 30),
    1,
);
