/**
 * 552. Student Attendance Record II
 * https://leetcode.com/problems/student-attendance-record-ii/description/
 */

const factCache = new Map()

const factorial = (n) => {
    if (typeof factCache.get(n) === 'number') return factCache.get(n)

    if (n == 0) return 1

    let f_val = n * factorial(n - 1)
    factCache.set(n, f_val)
    return f_val
}

const nPr = (n, r) => factorial(n) / factorial(n - r)
const nCr = (n, r) => factorial(n) / ( factorial(n - r) * factorial(r) )

// P
// L ! LL >= 3
// A ! > 1
var checkRecord = function(n) {
    const totol_p = Math.pow(3, n)

    let invalid_A = 0;
    let invalid_P = 0; 

    // for (let ia = 2; ia <= n; ++ia) {
    //     invalid_A = invalid_A 
    //     + nPr(1, n - ia)
    //     + nPr()
    // }

    // for (let i = 0; i < n; ++i) {
        
    // }

    for (let i = 0; i < n; ++i) {
        invalid_A = invalid_A
        + 
    }

    return totol_p - invalid_A - invalid_P

    // const all_P = 1 // nPr(n, 0)
    // const all_1_A_P = n // nPr(n, 1)
    // console.log(all_P, all_1_A_P);
    // return all_P + all_1_A_P
};

export { checkRecord }

console.log("$#", checkRecord(121));
