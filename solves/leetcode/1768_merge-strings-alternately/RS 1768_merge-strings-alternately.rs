use std::cmp;

impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let mut s = "".to_owned();
        for i in 0..cmp::max(word1.len(), word2.len()) {
            if i < word1.len() {
                s.push(word1.chars().nth(i).expect("CHAR"));
            }
            if i < word2.len() {
                s.push(word2.chars().nth(i).expect("CHAR"));
            }
        }
        return s;
    }
}
