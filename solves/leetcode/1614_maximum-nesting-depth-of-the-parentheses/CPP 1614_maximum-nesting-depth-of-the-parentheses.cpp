class Solution
{
public:
    int maxDepth(const string s)
    {
        int mx = 0;
        int curr = 0;
        for (auto &e : s)
        {
            if (e == '(')
            {
                curr++;
                mx = max(mx, curr);
            }
            else if (e == ')')
            {
                curr--;
            }
        }
        return mx;
    }
};