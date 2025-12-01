impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut result = 0x0;

        for n in nums {
            if n % 0x3 != 0x0 {
                result += 0x1;
            }
        }

        result
    }
}
