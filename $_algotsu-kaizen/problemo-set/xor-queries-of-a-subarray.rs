impl Solution {

    pub fn xor_queries(arr: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut xor: i32 = 0b0;
        let mut prexor: Vec<i32> = Vec::new();
        let mut result: Vec<i32> = Vec::new();
        let mut idx: usize = 0;

        for e in arr {
            xor = xor ^ e;
            prexor.push(xor);
        }

        for querie in queries {
            let l = querie[0] as usize;
            let r = querie[1] as usize;
            result.push((if l > 0 { prexor[l - 1] } else { 0 } ) ^ prexor[r]);
        }

        result
    }
}
