class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int r = grid.size(), c = grid[0].size();
        int mod = grid[0][0] % x;
        int flattened[r * c];
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] % x != mod)
                    return -1;
                flattened[i * c + j] = grid[i][j];
            }
        }
        sort(flattened, flattened + r * c);
        int mid = flattened[(r * c) >> 1];
        int res = 0;
        for (int v : flattened)
        {
            res += abs(v - mid) / x;
        }
        return res;
    }
};