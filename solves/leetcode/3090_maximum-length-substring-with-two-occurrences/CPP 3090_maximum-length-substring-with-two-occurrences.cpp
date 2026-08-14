class Solution
{
public:
    int maximumLengthSubstring(const string s)
    {
        const int n = s.size();
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int ln = 0;
            vector<int> ch(26, 0);

            for (int j = i; j < n; j++)
            {
                ch[s[j] - 'a']++;
                if (ch[s[j] - 'a'] > 2)
                {
                    break;
                }
                ln++;
            }
            mx = max(mx, ln);
        }
        return mx;
    }
};