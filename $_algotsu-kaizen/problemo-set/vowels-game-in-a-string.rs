impl Solution {

    fn is_vowel(c: char) -> bool {
        matches!(c.to_ascii_lowercase(), 'a' | 'e' | 'i' | 'o' | 'u')
    }

    pub fn does_alice_win(s: String) -> bool {
        let mut fv: u32 = 0x0;

        for c in s.chars() {
            if Self::is_vowel(c) {
                fv += 0x1;
            }
        }

        fv != 0x0
    }
}
