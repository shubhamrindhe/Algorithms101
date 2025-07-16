impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let (mut parities, mut alternate) = ([0x0, 0x0], 0x1);
        let (mut parity, mut parity_minus_one) = (0x0, (nums[0] & 0x1) as usize);

        for (i, n) in nums.into_iter().enumerate() {
            parity = (n & 0x1) as usize;
            parities[parity] += 0x1;
            if i > 0 && parity_minus_one != parity {
                alternate += 1;
                parity_minus_one = parity;
            }
        }

        if let Some(max) = parities.iter().max() {
            return std::cmp::max(*max, alternate);
        }

        alternate
    }
}
