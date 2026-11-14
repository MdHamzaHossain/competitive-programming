// TODO
class Solution
{
public:
    int minimumSumSubarray(vector<int> &nums, int l, int r)
    {
        int n = nums.size();
        const int INF = INT_MAX;
        int minSum = INF;

        for (int start = 0; start < n; ++start)
        {
            int currentSum = 0;

            for (int end = start; end < n; ++end)
            {
                currentSum += nums[end];
                int subarrayLength = end - start + 1;

                if (subarrayLength >= l && subarrayLength <= r && currentSum > 0)
                {
                    minSum = min(minSum, currentSum);
                }
            }
        }

        return minSum == INF ? -1 : minSum;
    }
};
