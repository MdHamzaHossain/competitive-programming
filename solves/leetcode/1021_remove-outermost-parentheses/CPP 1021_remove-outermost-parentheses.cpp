class Solution
{
public:
    string removeOuterParentheses(const string s)
    {
        string res = "";
        int count = 0;
        for (auto &e : s)
        {
            if (e == '(')
            {
                count++;
                if (count != 1)
                    res += e;
            }
            else
            {
                count--;
                if (count != 0)
                    res += e;
            }
        }
        return res;
    }
};