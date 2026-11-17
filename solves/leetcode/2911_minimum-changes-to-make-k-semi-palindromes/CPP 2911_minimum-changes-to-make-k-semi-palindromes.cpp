// TODO
class Solution
{
public:
    int minimumChanges(string s, int k)
    {
        int n = s.size();

        int minChanges[n + 1][n + 1];

        int dp[n + 1][k + 1];

        memset(minChanges, 0x3f, sizeof(minChanges));
        memset(dp, 0x3f, sizeof(dp));

        dp[0][0] = 0;

        for (int start = 1; start <= n; ++start)
        {
            for (int end = start; end <= n; ++end)
            {
                int length = end - start + 1;

                for (int period = 1; period < length; ++period)
                {
                    if (length % period == 0)
                    {
                        int changesNeeded = 0;

                        for (int leftIdx = 0; leftIdx < length; ++leftIdx)
                        {

                            int rightIdx = (length / period - 1 - leftIdx / period) * period + leftIdx % period;

                            if (leftIdx >= rightIdx)
                            {
                                break;
                            }

                            if (s[start - 1 + leftIdx] != s[start - 1 + rightIdx])
                            {
                                ++changesNeeded;
                            }
                        }

                        minChanges[start][end] = min(minChanges[start][end], changesNeeded);
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {

                for (int prevEnd = 0; prevEnd < i - 1; ++prevEnd)
                {

                    dp[i][j] = min(dp[i][j], dp[prevEnd][j - 1] + minChanges[prevEnd + 1][i]);
                }
            }
        }

        return dp[n][k];
    }
};
