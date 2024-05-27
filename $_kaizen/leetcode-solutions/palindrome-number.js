/**
 * 9. Palindrome Number
 * https://leetcode.com/problems/palindrome-number/description/
 */

var isPalindrome = function (x) {
    if (x < 0) return false;
    let ns = x.toString()

    let left = 0, right = ns.length - 1
    while (left <= right) {
        if (ns.charAt(left++) != ns.charAt(right--)) return false
    }

    return true;
};

var isPalindrome2 = function (x) {
    if (x < 0) return false;

    let aux_n = x
    let original = x
    let reversed = 0

    while (aux_n) {
        let remainder = aux_n % 10
        let quotient = Math.floor(aux_n / 10)
        reversed = reversed * 10 + remainder; 
        aux_n = quotient // Math.floor(aux_n / 10)
    }

    return reversed == original;
};

export { isPalindrome, isPalindrome2 }

console.log("$#", isPalindrome2(121));