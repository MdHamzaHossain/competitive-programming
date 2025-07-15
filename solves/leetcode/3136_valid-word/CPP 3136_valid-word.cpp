class Solution
{
public:
    bool isValid(string word)
    {
        if (word.size() < 3)
            return false;
        int has_vowel = 0, has_consonant = 0;
        vector<int> vs(26, 0);
        string vowels = "aeiou";
        for (char c : vowels)
            vs[c - 'a'] = 1;
        for (char c : word)
        {
            if (isalpha(c))
            {
                if (vs[tolower(c) - 'a'])
                    has_vowel = true;
                else
                    has_consonant = true;
            }
            else if (!isdigit(c))
                return false;
        }
        return has_vowel && has_consonant;
    }
};