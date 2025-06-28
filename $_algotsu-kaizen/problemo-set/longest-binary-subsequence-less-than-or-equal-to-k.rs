impl Solution {

    pub fn longest_subsequence(string: String, k: i32) -> i32 {
        let (mut result, mut n): (i32, i64) = (0x0 , 0x0);

        for (bit_idx, bit) in string.chars().rev().enumerate() {
            if bit == '0' {
                result += 1;
            } else if bit_idx < 0x1F {
                n += 0x1 << bit_idx;
                if n <= k as i64 {
                    result += 0x1
                }
            }
        }

        result
    }
}
