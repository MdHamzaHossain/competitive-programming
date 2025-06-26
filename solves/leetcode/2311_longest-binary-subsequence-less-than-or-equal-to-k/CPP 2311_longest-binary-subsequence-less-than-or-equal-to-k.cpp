class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int res = 0;
        int t = 0;

        for (int i = s.size() - 1; i >= 0; --i)
            if (s[i] == '0')
                ++res;
            else if (res < 30 && (t | (1 << res)) <= k)
                t |= 1 << (res++);
        return res;
    }
};
