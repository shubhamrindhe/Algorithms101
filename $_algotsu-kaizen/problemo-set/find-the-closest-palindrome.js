/**
 * 564. Find the Closest Palindrome
 * https://leetcode.com/problems/find-the-closest-palindrome/description/
 */

/**
 * @param {string} n
 * @return {string}
 */
var nearestPalindromic = function(n) {
    let number = BigInt(n)
    if (number < 9n) return (number - 1n).toString()

    let prefix = BigInt(n.slice(0, (n.length + 1) / 2));

    const palindrome = (prefix, isEven) => {
        let palindrome = prefix
        if (!isEven) prefix = prefix / 10n

        while (prefix > 0n) {
            palindrome = palindrome * 10n + prefix % 10n
            prefix = prefix / 10n
        }
    
        return palindrome
    }

    let isEven = n.length % 2 === 0

    let list = [
        palindrome(prefix - 1n, isEven),
        palindrome(prefix, isEven),
        palindrome(prefix + 1n, isEven),
        BigInt(10n ** BigInt(n.length - 1)) - 1n,
        BigInt(10n ** BigInt(n.length)) + 1n
    ]

    console.log(list);
    

    let kai = BigInt(Number.MAX_SAFE_INTEGER)
    let output = 0n

    for (const palindrome of list) {
        if (palindrome === number) continue
        let diff = number > palindrome ? number - palindrome : palindrome - number
        if (kai > diff || (kai === diff && palindrome < output)) {
            output = palindrome
            kai = diff
        }
    }

    return output.toString()
};

export { nearestPalindromic }

// Input: n = "123"
// Output: "121"
console.log("$#",
    nearestPalindromic(
        "1234555"
    ),
    "121"
);

// Input: n = "1"
// Output: "0"
console.log("$#",
    nearestPalindromic(
        "1"
    ),
    "0"
);


// 1234, 999, 1000
console.log("$#",
    nearestPalindromic(
        "1234"
    ),
    "1221"
);
console.log("$#",
    nearestPalindromic(
        "999"
    ),
    "1001"
);
console.log("$#",
    nearestPalindromic(
        "1000"
    ),
    "999"
);


console.log("$#",
    nearestPalindromic(
        "11"
    ),
    "9"
);

// 12932, 99800, 12120
console.log("$#",
    nearestPalindromic(
        "12932"
    ),
    "1221"
);
console.log("$#",
    nearestPalindromic(
        "99800"
    ),
    "99899"
);
console.log("$#",
    nearestPalindromic(
        "12120"
    ),
    "12121"
);
