// TODO
class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            long long powerOfI = (long long)pow(i, x);
            for (int j = 0; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (powerOfI <= j)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - powerOfI]) % MOD;
            }
        }
        return dp[n][n];
    }
};
