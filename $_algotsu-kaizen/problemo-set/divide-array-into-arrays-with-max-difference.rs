impl Solution {
    pub fn divide_array(mut nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::with_capacity(nums.len() / 0b11);
        nums.sort();
        let mut idx = 0b0;

        while idx < nums.len() {
            if nums[idx + 0b10] - nums[idx] <= k {
                let slice = &nums[idx..=(idx + 0b10)];
                result.push(slice.to_vec());
            } else {
                return Vec::new();
            }

            idx += 0b11;
        }

        result
    }
}
