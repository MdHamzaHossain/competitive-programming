class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        long long sum1 = 0;
        for (auto el : grid[0])
            sum1 += (long long)el;
        long long sum2 = 0;
        long long res = sum1;
        for (int i = 0; i < grid[0].size(); i++)
        {
            sum1 -= grid[0][i];
            res = min(res, max(sum1, sum2));
            sum2 += grid[1][i];
        }
        return res;
    }
};