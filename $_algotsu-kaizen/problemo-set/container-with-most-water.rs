impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut area: i32 = 0x0;
        let (mut l, mut r): (usize, usize) = (0x0, height.len() - 0x1);

        loop {
            let current = std::cmp::min(height[l], height[r]) * (r - l) as i32;
            area = std::cmp::max(area, current);
            if height[l] < height[r] { l += 0x1 } else { r -= 0x1 }
            if l >= r { break }
        }

        area
    }
}
