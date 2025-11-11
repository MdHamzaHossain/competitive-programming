// TODO
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        const int numStrings = strs.size();
        vector<vector<vector<int>>> dp(numStrings + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // int dp[numStrings + 1][m + 1][n + 1];
        // memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= numStrings; ++i)
        {
            const string s = strs[i - 1];
            const int si = s.size();
            const int ones = count_if(s.begin(), s.end(), [](char e) -> bool
                                      { return e == '1'; });

            const int zeroes = si - ones;

            for (int j = 0; j <= m; ++j)
            {

                for (int k = 0; k <= n; ++k)
                {

                    dp[i][j][k] = dp[i - 1][j][k];

                    if (j >= zeroes && k >= ones)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeroes][k - ones] + 1);
                    }
                }
            }
        }

        return dp[numStrings][m][n];
    }
};