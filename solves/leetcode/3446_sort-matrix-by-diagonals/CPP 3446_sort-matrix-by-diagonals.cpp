class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int size = grid.size();
        map<int, vector<int>> temp;
        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < size; y++)
                temp[x - y].push_back(grid[x][y]);
        }
        for (auto &[k, v] : temp)
        {
            if (k >= 0)
                sort(v.begin(), v.end());
            else
                sort(v.rbegin(), v.rend());
        }
        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < size; y++)
            {
                grid[x][y] = temp[x - y].back();
                temp[x - y].pop_back();
            }
        }
        return grid;
    }
};
