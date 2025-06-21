impl Solution {
    pub fn partition_array(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let mut result: i32 = 0;
        let (mut l, mut r): (usize, usize) = (0usize, 0usize);

        while l < nums.len() {
            r = l;
            while (r < (nums.len() - 1usize)) && (nums[r + 1] - nums[l] <= k) {
                r += 1;
            }

            l = r + 1;
            result += 1;
        }

        result
    }
}
