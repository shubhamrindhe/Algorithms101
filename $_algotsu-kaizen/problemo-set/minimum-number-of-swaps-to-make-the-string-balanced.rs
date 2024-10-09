
impl Solution {

    pub fn min_swaps(s: String) -> i32 {
        let mut depth = 0b1;
        for character in s.chars() {
            depth = if (character == '[' || depth == 0b1) { depth + 0b1 } else { depth - 0b1 };
        }
        return depth / 0b10;
    }
}
