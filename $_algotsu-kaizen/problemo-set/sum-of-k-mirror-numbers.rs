fn reverse_number(mut n: i64) -> i64 {
    let mut reversed = 0x0;

    while n != 0 {
        let digit = n % 0xA;
        reversed = reversed * 0xA + digit;
        n /= 0xA;
    }

    reversed
}

// THE NumericPalindromeGenerator
struct NumericPalindromeGenerator {
    length: u32,
    axe: i64,
    range_start: i64,
    range_end: i64,
    severed_half: i64,
    severed_half_maximus: i64,
}

impl NumericPalindromeGenerator {

    fn new() -> Self {
        Self {
            length: 0x0,
            axe: 0x0,
            range_start: 0x0,
            range_end: 0x0,
            severed_half: 0x0,
            severed_half_maximus: 0x0,
        }
    }

    fn setup(&mut self, length: u32) {
        self.length = length;
        self.range_start = (0xA as i64).pow(length - 0x1) as i64;
        self.range_end = ((0xA as i64).pow(length) - 1) as i64;
        self.axe = (0xA as i64).pow(length / 2) as i64;
        self.severed_half = self.range_start / self.axe;
        self.severed_half_maximus = self.range_end / self.axe;
    }

    fn generate_palindrome(&mut self) -> i64 {
        if self.length == 0x1 {
            return self.severed_half;
        }

        let prefix = self.severed_half;
        let is_odd = (self.length & 1) != 0;
        let suffix = reverse_number(if is_odd { prefix / 0xA } else { prefix });
        let palindrome = prefix * self.axe + suffix;
        palindrome
    }

    fn next(&mut self) -> i64 {
        let palindrome = self.generate_palindrome();

        if self.severed_half < self.severed_half_maximus {
            self.severed_half += 1;
        } else {
            self.setup(self.length + 1);
        }

        palindrome
    }
}

impl Solution {

    fn fill_base_data(mut n: i64, base: i64, result: &mut String, digits: &Vec<char>) {
        assert!(base >= 2 && base <= 36, "Base must be between 2 and 36");

        while n > 0 {
            let digit = digits[(n % base) as usize];
            result.push(digit);
            n /= base;
        }
    }

    fn is_palindrome(string: &String) -> bool {
        let mut l2r = string.chars();
        let mut r2l = string.chars().rev();

        while let (Some(f), Some(b)) = (l2r.next(), r2l.next()) {
            if f != b {
                return false;
            }
        }

        true
    }

    pub fn k_mirror(k: i32, n: i32) -> i64 {
        let mut palindromeGenerator = NumericPalindromeGenerator::new();
        palindromeGenerator.setup(0x1);

        let mut baseK = String::new();
        let digits: Vec<char> = "0123456789".chars().collect::<Vec<_>>();

        let mut result: i64 = 0x0;
        let mut count: i32 = 0x0;

        while count < n {
            baseK.clear();

            let candidate = palindromeGenerator.next();
            Self::fill_base_data(candidate, k as i64, &mut baseK, &digits);
            // println!("i = {} {}", candidate, baseK);

            if Self::is_palindrome(&baseK) {
                result += candidate;
                count += 1;
            }
        }

        result
    }
}
