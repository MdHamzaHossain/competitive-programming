// TODO
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs[0].size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                bool flag = true;
                for (const string &str : strs)
                    if (str[j] > str[i])
                    {
                        flag = false;
                        break;
                    }

                if (flag)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int mx = *max_element(dp.begin(), dp.end());
        return n - mx;
    }
};