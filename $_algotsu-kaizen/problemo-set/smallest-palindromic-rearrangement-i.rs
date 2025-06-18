macro_rules! char_idx {
    ($c:expr) => {
        (($c as u8) - ('a' as u8)) as usize
    };
}

macro_rules! char_next {
    ($c:expr) => {
        ($c as u8 + 0b01) as char
    };
}

impl Solution {
    pub fn smallest_palindrome(s: String) -> String {
        let mut stream: Vec<char> = s.chars().collect();
        let mut f: Vec<i32> = vec![0; 0x1A];

        for c in &stream {
            f[char_idx!(*c)] += 0b01;
        }

        let mut l: usize = 0;
        let mut r: usize = stream.len() - 1;

        let mut c: char = 'a';
        while l < r && c <= 'z' {
            while f[char_idx!(c)] >= 0b10 {
                stream[l] = c;
                stream[r] = c;
                l += 1;
                r -= 1;
                f[char_idx!(c)] -= 0b10;
            }

            c = char_next!(c);
        }

        stream.into_iter().collect()
    }
}
