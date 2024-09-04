struct Solution {
}

impl Solution {
    pub fn chalk_replacer(chalk: Vec<i32>, k: i32) -> i32 {
        // let mut sigma = 0x0;
        // for c in chalk.iter() { sigma += c; }
        // let mut value = if k >= sigma { k % sigma } else { k };
        // let mut idx = 0b0;
        // for c in chalk.iter() {
        //     if (value < k) {
        //         break
        //     }
        //     value -= c;
        //     idx += 0x1;
        // }
        // idx

        let total_chalk: i64 = chalk.iter().map(|&x| x as i64).sum();
        let k = k as i64 % total_chalk;
        let mut current_chalk = 0;
        for (idx, &chalk_needed) in chalk.iter().enumerate() {
            let chalk_needed = chalk_needed as i64;
            if k < current_chalk + chalk_needed {
                return idx as i32;
            }
            current_chalk += chalk_needed;
        }
        -0x1
    }
}
// impl Solution {
//     pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>> {
//         let size = m * n;
//         if original.len() != size as usize {
//             return vec![];
//         }
//
//         let mut matrix = vec![vec![0x0; n as usize]; m as usize];
//         let mut idx: i32 = 0x0;
//         for element in original {
//             matrix[(idx / n) as usize][(idx % n) as usize] = element;
//             idx += 0x1;
//         }
//
//         matrix
//     }
// }

fn main() {
    println!("Hello World!");
}