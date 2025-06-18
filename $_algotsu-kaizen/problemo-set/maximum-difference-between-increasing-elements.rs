impl Solution {

    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        let mut result: i32 = -1;
        let mut r = nums.len() - 1;
        let mut l = r;

        while l > 0 {
            l -= 1;

            if nums[l] < nums[r] {
                result = std::cmp::max(result, nums[r] - nums[l]);
            } else if nums[l] > nums[r] {
                r = l;
            }
        }

        result
    }
}
