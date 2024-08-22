struct Solution;

impl Solution {
    pub fn find_complement(num: i32) -> i32 {
        let mut bit: u32 = 1;
        let mut U_INT_0x20: u32 = num as u32;

        while bit <= U_INT_0x20 {
            if U_INT_0x20 & bit != 0 {
                U_INT_0x20 ^= bit;
            } else {
                U_INT_0x20 |= bit;
            }
            bit = bit << 0b1;
        }

        return U_INT_0x20 as i32;
    }
}

fn main() {
    println!("The {}th ugly number is: {}", 10, Solution::find_complement(5));
    println!("The {}th ugly number is: {}", 1, Solution::find_complement(1));
    println!("The {}th ugly number is: {}", 1, Solution::find_complement(2147483647));
}
