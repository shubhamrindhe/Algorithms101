impl Solution {
    pub fn max_distance(s: String, k: i32) -> i32 {
        let (mut maximus, mut dx, mut dy): (i32, i32, i32) = (0x0, 0x0, 0x0);

        // let mut map = std::collections::HashMap::from([
        //     ('N', 0x0),
        //     ('E', 0x0),
        //     ('S', 0x0),
        //     ('W', 0x0)
        // ]);

        for (idx, dir) in s.chars().enumerate() {
            match dir {
                'N' => dy += 0x1,
                'E' => dx += 0x1,
                'S' => dy -= 0x1,
                'W' => dx -= 0x1,
                _ => std::process::exit(0),
            }
            let current_manhattan = std::cmp::min(dx.abs() + dy.abs() + 0x2 * k, idx as i32 + 0x1);

            // *map.entry(dir).or_insert(0) += 1;
            // let N = map.get(&'N').unwrap();
            // let E = map.get(&'E').unwrap();
            // let S = map.get(&'S').unwrap();
            // let W = map.get(&'W').unwrap();
            // let mut available_swaps = k;
            // let vertical_swaps = std::cmp::min(std::cmp::min(*N, *S), available_swaps);
            // available_swaps -= vertical_swaps;
            // let horizontal_swaps = std::cmp::min(std::cmp::min(*W, *E), available_swaps);
            // let displacement_x = W.abs_diff(*E) as i32 + 0x2 * vertical_swaps;
            // let displacement_y = N.abs_diff(*S) as i32 + 0x2 * horizontal_swaps;
            // let current_manhattan = displacement_x + displacement_y;

            maximus = std::cmp::max(maximus, current_manhattan);
        }

        maximus
    }
}
