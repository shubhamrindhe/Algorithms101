
impl Solution {
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let mut count: i32 = 0b0;
        let mut chars = std::collections::HashSet::new();

        for c in allowed.chars() { 
            chars.insert(c);
        }

        for word in words { 
            let mut flag = true;
            for c in word.chars() { 
                if chars.contains(&c) {
                    continue;
                }

                flag = false;
                break;
            }

            if flag {
                count += 1;
            }
        }

        return count;
    }
}
