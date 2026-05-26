class Solution
{
public:
    int numberOfSpecialChars(const string &word)
    {
        bitset<52> charFlag;
        for (auto &e : word)
        {
            charFlag[e - 'A' + !(e <= 'Z') * (-6)] = 1;
        }
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            res += charFlag[i] & charFlag[26 + i];
        }
        return res;
    }
};