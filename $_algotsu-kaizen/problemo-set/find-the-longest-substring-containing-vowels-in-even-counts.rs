
impl Solution {

    pub fn find_the_longest_substring(s: String) -> i32 {
        let a_mask = 0b00001;
        let e_mask = 0b00010;
        let i_mask = 0b00100;
        let o_mask = 0b01000;
        let u_mask = 0b10000;

        let mut bits = vec![-0b10; 0x20];
        bits[0b0] = -0b1;
        let mut max_len = 0b0;
        let mut idx = 0b0;
        let mut state = 0b0;

        for char in s.chars() {
            match char {
                'a' => state ^= a_mask,
                'e' => state ^= e_mask,
                'i' => state ^= i_mask,
                'o' => state ^= o_mask,
                'u' => state ^= u_mask,
                _ => (),
            }

            let xidx = bits[state];
            if (xidx == -0b10) {
                bits[state] = idx;
            } else {
                max_len = std::cmp::max(max_len, idx - xidx);
            }
            idx += 0b1;
        }

        max_len
    }
}
