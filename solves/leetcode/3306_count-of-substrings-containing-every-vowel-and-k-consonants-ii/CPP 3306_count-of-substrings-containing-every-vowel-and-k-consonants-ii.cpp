
class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    long long countOfSubstrings(string word, int k)
    {
        return helper(word, k) - helper(word, k - 1);
    }
    long helper(const string &word, int k)
    {
        if (k == -1)
            return 0;

        long long answer = 0;
        int vows = 0;
        int vowsUnique = 0;
        unordered_map<char, int> lastVow;

        for (int l = 0, r = 0; r < word.length(); ++r)
        {
            if (isVowel(word[r]))
            {
                vows++;
                if (const auto it = lastVow.find(word[r]);
                    it == lastVow.end() || it->second < l)
                    vowsUnique++;
                lastVow[word[r]] = r;
            }
            while (r - l + 1 - vows > k)
            {
                if (isVowel(word[l]))
                {
                    vows--;
                    if (lastVow[word[l]] == l)
                        vowsUnique--;
                }
                l++;
            }
            if (vowsUnique == 5)
                answer += min({lastVow['a'], lastVow['e'], lastVow['i'],
                               lastVow['o'], lastVow['u']}) -
                          l + 1;
        }

        return answer;
    }
};