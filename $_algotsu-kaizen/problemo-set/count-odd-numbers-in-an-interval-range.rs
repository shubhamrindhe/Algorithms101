impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        return ((high + 0x1) >> 0x1) - ((low) >> 0x1);
    }
}
