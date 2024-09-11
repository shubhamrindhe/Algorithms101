impl Solution {

    pub fn min_bit_flips(start: i32, goal: i32) -> i32 {
        let mut bit: u32 = 0b1;
        let mut kai_bits: u32 = 0b0;
        let max = if (start > goal) { start as u32 } else { goal as u32 };

        while bit <= max {
            if ((goal as u32 & bit) ^ (start as u32 & bit)) != 0b0 {
                kai_bits += 0b1;
            }

            bit = bit << 0b1;
        }

        return kai_bits as i32;
    }
}
