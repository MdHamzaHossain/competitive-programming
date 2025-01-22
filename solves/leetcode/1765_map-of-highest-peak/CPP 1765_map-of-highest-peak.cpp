class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = isWater.size(), n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> dq;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    dq.emplace(i, j);
                    ans[i][j] = 0;
                }
            }
        }
        while (!dq.empty())
        {
            auto [i, j] = dq.front();
            dq.pop();
            for (auto &[dx, dy] : dirs)
            {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || y < 0 || x == m || y == n || (ans[x][y] != -1))
                    continue;
                ans[x][y] = ans[i][j] + 1;
                dq.emplace(x, y);
            }
        }
        return ans;
    }
};