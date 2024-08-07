/**
 * 273. Integer to English Words
 * https://leetcode.com/problems/integer-to-english-words/description/
 */

const UNIT_MAP = {
  0: "Zero",
  1: "One",
  2: "Two",
  3: "Three",
  4: "Four",
  5: "Five",
  6: "Six",
  7: "Seven",
  8: "Eight",
  9: "Nine",
};

const TENTH_MAP = {
  10: "Ten",
  11: "Eleven",
  12: "Twelve",
  13: "Thirteen",
  14: "Fourteen",
  15: "Fifteen",
  16: "Sixteen",
  17: "Seventeen",
  18: "Eighteen",
  19: "Nineteen",
  20: "Twenty",
  30: "Thirty",
  40: "Forty",
  50: "Fifty",
  60: "Sixty",
  70: "Seventy",
  80: "Eighty",
  90: "Ninety",
};

const THE_PLACE_VALUE_MAP = {
  ...UNIT_MAP,
  ...TENTH_MAP,
};

/**
 * @param {number} num
 * @return {string}
 */
var numberToWords = function (num) {
  if (num in THE_PLACE_VALUE_MAP) return THE_PLACE_VALUE_MAP[num];

  const placeValue = Math.floor(Math.log10(num));
  const divisor = Math.pow(0o12, Math.floor(placeValue / 0o3) * 0o3);
  const next = num % divisor;
  const current = Math.floor(num / divisor);

  const d1 = Math.floor(current % 0o12);
  const d10 = Math.floor((current / 0xa) % 0o12);
  const d100 = Math.floor((current / 0x64) % 0o12);

  return [
    d100 != 0x0 ? UNIT_MAP[d100] + " Hundred" : null,
    d10 != 0x0 ? TENTH_MAP[d10 * 10 + d1] || TENTH_MAP[d10 * 10] : null,
    d1 != 0x0 && d10 != 0x1 ? UNIT_MAP[d1] : null,
    num >= 1_000_000_000
      ? "Billion"
      : num >= 1_000_000
      ? "Million"
      : num >= 1_000
      ? "Thousand"
      : null,
  ]
    .filter((e) => Boolean(e))
    .concat(Boolean(next) ? numberToWords(next) : [])
    .join(" ");
};

export { numberToWords };

// Input: num = 123;
// Output: "One Hundred Twenty Three";
console.log("$#", numberToWords(123), "--", "One Hundred Twenty Three");

// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
console.log(
  "$#",
  numberToWords(12345),
  "--",
  "Twelve Thousand Three Hundred Forty Five"
);

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
console.log(
  "$#",
  numberToWords(1234567),
  "--",
  "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
);

console.log("$#", numberToWords(100), "--", "One Hundred");

console.log("$#", numberToWords(1000), "--", "One Thousand");

console.log(numberToWords(0));

console.log(numberToWords(12));

console.log(numberToWords(123));

console.log(numberToWords(12_345));

console.log(numberToWords(123_456));

console.log(numberToWords(123_456_789));

console.log(numberToWords(9_123_456_789));

console.log(numberToWords(10_123_456_001));
