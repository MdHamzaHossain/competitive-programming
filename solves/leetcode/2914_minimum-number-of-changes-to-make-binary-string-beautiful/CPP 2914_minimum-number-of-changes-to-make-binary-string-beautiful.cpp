class Solution
{
public:
    int minChanges(string s)
    {
        int res = 0;
        char prev = s[0];
        for (int i = 1; i < s.size(); i += 2)
        {
            if (s[i - 1] != s[i])
                res++;
        }
        return res;
    }
};