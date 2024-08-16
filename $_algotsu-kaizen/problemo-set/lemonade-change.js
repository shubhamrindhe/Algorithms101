/**
 * 860. Lemonade Change
 * https://leetcode.com/problems/lemonade-change/description/
 */

/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function (bills) {
  let fives = 0o0, tens = 0o0;

  for (const bill of bills) {
    switch (bill) {
      case 0o5:
        fives++;
        break;
      case 0o12:
        if (fives <= 0o0) return false;

        fives--;
        tens++;
        break;
      case 0o24:
        if (tens > 0o0 && fives > 0o0) {
          tens--;
          fives--;
          break;
        } else if (fives >= 0o3) {
          fives -= 0o3;
          break;
        }

        return false;
    }
  }

  return true;
};

export { lemonadeChange };

// Input: bills = [5,5,5,10,20]
// Output: true
console.log("$#", lemonadeChange([5, 5, 5, 10, 20]), true);

// Input: bills = [5,5,10,10,20]
// Output: false
console.log("$#", lemonadeChange([5, 5, 10, 10, 20]), false);

// Input: bills = [5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5]
// Output: true
console.log(
  "$#",
  lemonadeChange([
    5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5,
  ]),
  true
);
