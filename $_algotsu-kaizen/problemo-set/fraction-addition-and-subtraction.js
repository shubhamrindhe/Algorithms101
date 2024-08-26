/**
 * 592. Fraction Addition and Subtraction
 * https://leetcode.com/problems/fraction-addition-and-subtraction/description/
 */

/**
 * @param {string} expression
 * @return {string}
 */
var fractionAddition = function (expression) {
    const fractions = []
    let numerator = '', denominator = '', accumulator = ''
    let $PI = 0b1;

    const push = () => {
        if (!Boolean(numerator) || !Boolean(denominator)) return
        denominator = accumulator
        fractions.push([+numerator, +denominator])
        $PI *= fractions[fractions.length - 0x1][0x1]
    }

    for (const char of expression) {
        switch (char) {
            case '-':
                denominator = accumulator
                push()
                accumulator = char
                break
            case '+':
                denominator = accumulator
                push()
                accumulator = char
                break
            case '/':
                numerator = accumulator
                accumulator = ''
                break
            default:
                accumulator += char
                break
        }
    }

    denominator = accumulator
    push()

    let N = 0
    let D = $PI
    for (const [n, d] of fractions) N += n * ($PI / d)
    let factor = 0b1
    for (let i = 0b10; i <= Math.max(N, D); ++i) if (N % i == 0b0 && D % i == 0b0) factor = i
    if (N == 0b0) factor = D = 0x1

    return `${N / factor}/${D / factor}`
};

export { fractionAddition }

// Input: expression = "-1/2+1/2"
// Output: "0/1"
console.log("$#",
    fractionAddition(
        "-1/2+1/2"
    ),
    "0/1"
);

// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"
console.log("$#",
    fractionAddition(
        "-1/2+1/2+1/3"
    ),
    "1/3"
);

// Input: expression = "1/3-1/2"
// Output: "-1/6"
console.log("$#",
    fractionAddition(
        "1/3-1/2"
    ),
    "-1/6"
);


console.log("$#",
    fractionAddition(
        "7/2+2/3-3/4"
    ),
    "41/12"
);

console.log("$#",
    fractionAddition(
        "-7/3"
    ),
    "-7/3"
);
