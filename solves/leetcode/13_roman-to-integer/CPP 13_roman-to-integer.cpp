class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if ((i + 1 < s.size()) && romanMap[s[i]] < romanMap[s[i + 1]])
            {
                res += romanMap[s[i + 1]] - romanMap[s[i]];
                i++;
            }
            else
                res += romanMap[c];
        }
        return res;
    }
};