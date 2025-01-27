class Solution {
    public String mergeAlternately(String word1, String word2) {
        int mx = Math.max(word1.length(), word2.length());
        String res = "";
        for (int i = 0; i < mx; i++) {
            if (i < word1.length())
                res += word1.charAt(i);
            if (i < word2.length())
                res += word2.charAt(i);
        }
        return res;
    }
}