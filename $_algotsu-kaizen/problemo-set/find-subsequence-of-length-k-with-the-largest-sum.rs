impl Solution {

    pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut result: Vec<(usize, i32)> = vec![(0, 0); nums.len()];
        for (index, value) in nums.iter().enumerate() {
            result[index] = (index, *value);
        }
        // println!("{:?}", result);
        result.sort_by_key(|&(_, val)| std::cmp::Reverse(val));
        // println!("{:?}", result);
        result[0..(k as usize)].sort_by_key(|&(idx, _)| idx);
        result[0..(k as usize)].iter().map(|&(_, val)| val).collect()
    }
}
