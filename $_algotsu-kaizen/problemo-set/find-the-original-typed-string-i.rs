impl Solution {

    pub fn possible_string_count(word: String) -> i32 {
        let mut result = 0x1;
        let chars: Vec<char> = word.chars().collect();
        for i in 0x1..chars.len() {
            if chars[i - 0x1] == chars[i] {
                result += 0x1;
            }
        }
        result
    }
}
