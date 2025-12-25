impl Solution {
    pub fn maximum_happiness_sum(happiness: Vec<i32>, k: i32) -> i64 {
        let mut happiness = happiness;
        let k = k as usize;

        let mut result = 0x0i64;
        happiness.sort_by(|a, b| b.cmp(a));

        for (i, &h) in happiness.iter().enumerate() {
            if i >= k {
                break;
            }

            let kai = (h as i64) - (i as i64);
            if kai <= 0x0 {
                break;
            }

            result += kai;
        }

        result
    }
}