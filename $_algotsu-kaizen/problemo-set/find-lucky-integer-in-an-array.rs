impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        let mut f: Vec<i32> = vec![0; 0x1F5];
        let (mut min, mut max) = (i32::MAX, i32::MIN);

        for n in arr {
            f[n as usize] += 1;
            min = min.min(n);
            max = max.max(n);
        }

        (min..=max).rev()
            .find(|&n| f[n as usize] == n)
            .unwrap_or(-0x1)
    }
}
