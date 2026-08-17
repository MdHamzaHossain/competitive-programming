// TODO
class Solution
{
public:
    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();

        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        auto dfs = [&](this auto &&dfs, int left, int right) -> int
        {
            if (left >= right)
            {
                return 0;
            }

            if (dp[left][right] != -1)
            {
                return dp[left][right];
            }

            int maxScore = 0;
            int leftSum = 0;
            int rightSum = prefixSum[right + 1] - prefixSum[left];

            for (int splitPoint = left; splitPoint < right; ++splitPoint)
            {
                leftSum += stoneValue[splitPoint];
                rightSum -= stoneValue[splitPoint];

                if (leftSum < rightSum)
                {

                    if (maxScore > leftSum * 2)
                    {
                        continue;
                    }
                    maxScore = max(maxScore, leftSum + dfs(left, splitPoint));
                }
                else if (leftSum > rightSum)
                {

                    if (maxScore > rightSum * 2)
                    {
                        break;
                    }
                    maxScore = max(maxScore, rightSum + dfs(splitPoint + 1, right));
                }
                else
                {

                    maxScore = max({maxScore,
                                    leftSum + dfs(left, splitPoint),
                                    rightSum + dfs(splitPoint + 1, right)});
                }
            }

            dp[left][right] = maxScore;
            return maxScore;
        };

        return dfs(0, n - 1);
    }
};
