struct Solution;

impl Solution {
    pub fn nth_ugly_number(n: i32) -> i32 {
        let mut ugly_list = vec![0; n as usize];
        ugly_list[0] = 0b1;
        let size = 0x1;
        let mut next = 0x1;
        let mut idx2 = 0b0;
        let mut idx3 = 0b0;
        let mut idx5 = 0b0;

        for i in 1..n {
            // println!("{} {}", i, ugly_list[i as usize]);
            let m2 = ugly_list[idx2] * 0b010;
            let m3 = ugly_list[idx3] * 0b011;
            let m5 = ugly_list[idx5] * 0b101;
            
            next = std::cmp::min(std::cmp::min(m2, m3), m5);
            ugly_list[i as usize] = next;
        
            if (next == m2) {
                idx2 += 1;
            }
            if (next == m3) {
                idx3 += 1;
            }
            if (next == m5) {
                idx5 += 1;
            }
        }
    
        next
    }
}

fn main() {
    println!("The {}th ugly number is: {}", 10, Solution::nth_ugly_number(10));
    println!("The {}th ugly number is: {}", 1, Solution::nth_ugly_number(1));
}

