impl Solution {

    fn generate(i: i32, n: i32) -> Vec<i32> {
        let mut result = Vec::new();
        if i > n { return result };
        result.push(i);
        result.append(&mut Self::generate(i * 10, n));

        if i % 10 < 9 {
            result.append(&mut Self::generate(i + 1, n));
        }

        return result;
    }

    pub fn lexical_order(n: i32) -> Vec<i32> {
        return Self::generate(0b1, n);
    }
}
