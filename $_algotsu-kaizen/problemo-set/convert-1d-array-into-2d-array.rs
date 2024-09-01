struct Solution {
}
impl Solution {
    pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>> {
        let size = m * n;
        if original.len() != size as usize {
            return vec![];
        }

        let mut matrix = vec![vec![0x0; n as usize]; m as usize];
        let mut idx: i32 = 0x0;
        for element in original {
            matrix[(idx / n) as usize][(idx % n) as usize] = element;
            idx += 0x1;
        }

        matrix
    }
}

fn main() {
    println!("Hello World!");
}