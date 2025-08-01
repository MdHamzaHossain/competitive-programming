class Solution
{
public:
    string makeFancyString(string s)
    {
        string res = "";
        for (auto c : s)
        {
            int n = res.size();
            if (n > 1 && res[n - 1] == c && res[n - 2] == c)
                continue;
            res += c;
        }

        return res;
    }
};