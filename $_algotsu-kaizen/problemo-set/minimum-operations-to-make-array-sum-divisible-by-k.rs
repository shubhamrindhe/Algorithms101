impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let sigma = nums.iter().fold(0, |acc, x| acc + x);

        // let mut sigma = 0x0;
        // for n in nums {
        //     sigma += n;
        // }

        sigma % k
    }
}
