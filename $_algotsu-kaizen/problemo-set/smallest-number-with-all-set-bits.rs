impl Solution {
    pub fn smallest_number(n: i32) -> i32 {
        let mut result = 0x01;
        while result <= n {
            result <<= 0x01;
        }
        result - 0x01
    }
}
