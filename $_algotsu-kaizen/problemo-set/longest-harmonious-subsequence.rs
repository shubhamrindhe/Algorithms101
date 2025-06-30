use std::collections::HashMap;

impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut map: HashMap<i32, i32> = HashMap::new();

        for num in nums {
            *map.entry(num).or_insert(0) += 1;
            // *map.entry(num).and_modify(|f| *f += 1).or_insert(1);
        }

        let mut maximus: i32 = 0;

        for (key, count) in &map {
            if let Some(value) = map.get(&(key - 1)) {
                maximus = std::cmp::max(maximus, count + *value);
            }
        }

        maximus
    }
}
