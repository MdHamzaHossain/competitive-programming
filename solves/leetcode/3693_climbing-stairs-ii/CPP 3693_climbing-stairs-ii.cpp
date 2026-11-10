// TODO
class Solution
{
public:
    int climbStairs(int n, vector<int> &costs)
    {

        vector<int> minCost(n + 1, INT_MAX / 2);

        minCost[0] = 0;

        for (int i = 1; i <= n; ++i)
        {

            int stepCost = costs[i - 1];

            for (int j = max(0, i - 3); j < i; ++j)
            {
                int jumpLength = i - j;

                minCost[i] = min(minCost[i],
                                 minCost[j] + stepCost + jumpLength * jumpLength);
            }
        }

        return minCost[n];
    }
};
