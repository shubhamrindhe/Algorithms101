
impl Solution {

    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut open = 0b0;
        let mut close = 0b0;
        for c in s.chars() {
            open += if c == '(' { 0b1 } else { -0b1 };
            if open < 0b0 {
                close += 0b1;
                open = 0b0;
            }
        }
        return open + close;
    }
}
