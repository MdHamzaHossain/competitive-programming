class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        map<char, int> charCount = {
            {'a', 0},
            {'b', 0},
            {'c', 0},
            {'d', 0},
            {'e', 0},
            {'f', 0},
            {'g', 0},
            {'h', 0},
            {'i', 0},
            {'j', 0},
            {'k', 0},
            {'l', 0},
            {'m', 0},
            {'n', 0},
            {'o', 0},
            {'p', 0},
            {'q', 0},
            {'r', 0},
            {'s', 0},
            {'t', 0},
            {'u', 0},
            {'v', 0},
            {'w', 0},
            {'x', 0},
            {'y', 0},
            {'z', 0}};
        unordered_set<char> uniques;
        if (k > s.size())
            return false;
        for (char c : s)
        {
            uniques.insert(c);
            charCount[c]++;
        }
        long long odds = 0;
        for (auto itr = uniques.begin(); itr != uniques.end(); itr++)
        {
            // the minimum amount of palindromes i can make will all the characters is the amount of ODDS + all with that one even
            if (charCount[*itr] % 2 == 1)
                odds++;
        }
        return odds <= k;
    }
};