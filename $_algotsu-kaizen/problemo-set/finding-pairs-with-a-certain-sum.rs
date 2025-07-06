use std::collections::HashMap;

struct FindSumPairs {
    nums1: Vec<i32>,
    nums2: Vec<i32>,
    f: HashMap<i32, i32>
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FindSumPairs {

    fn new(nums1: Vec<i32>, nums2: Vec<i32>) -> Self {
        let mut f = HashMap::new();
        for &n in &nums2 {
            *f.entry(n).or_insert(0) += 1;
        }

        Self {
            nums1,
            nums2,
            f
        }
    }

    fn add(&mut self, index: i32, val: i32) {
        let old = self.nums2[index as usize];
        *(self.f.entry(old).or_insert(1)) -= 1;
        self.nums2[index as usize] += val;
        let new = self.nums2[index as usize];
        *(self.f.entry(new).or_insert(0)) += 1;
    }

    fn count(&self, tot: i32) -> i32 {
        let mut result = 0;

        for n in &self.nums1 {
            if let Some(count) = self.f.get(&(tot - n)) {
                result += count;
            }
        }

        result
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * let obj = FindSumPairs::new(nums1, nums2);
 * obj.add(index, val);
 * let ret_2: i32 = obj.count(tot);
 */
