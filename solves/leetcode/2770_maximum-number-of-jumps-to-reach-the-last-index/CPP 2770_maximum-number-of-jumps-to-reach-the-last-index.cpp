// TODO
class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> dp(n, -1);

        function<int(int)> dfs = [&](int currentIndex) -> int
        {
            if (currentIndex == n - 1)
            {
                return 0;
            }

            if (dp[currentIndex] != -1)
            {
                return dp[currentIndex];
            }

            dp[currentIndex] = INT_MIN / 2;

            for (int nextIndex = currentIndex + 1; nextIndex < n; ++nextIndex)
            {

                if (abs(nums[currentIndex] - nums[nextIndex]) <= target)
                {

                    dp[currentIndex] = max(dp[currentIndex], 1 + dfs(nextIndex));
                }
            }

            return dp[currentIndex];
        };

        int result = dfs(0);

        return result < 0 ? -1 : result;
    }
};
