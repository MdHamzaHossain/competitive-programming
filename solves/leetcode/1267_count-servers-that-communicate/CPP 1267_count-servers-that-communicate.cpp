class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int x = grid.size();
        int y = grid[0].size();
        int ans = 0;
        vector<int> rows(x);
        vector<int> cols(y);

        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j)
                if (grid[i][j] == 1)
                {
                    rows[i]++;
                    cols[j]++;
                }

        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j)
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1))
                    ans++;

        return ans;
    }
};