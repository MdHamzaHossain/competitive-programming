class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        const int o = n * m;
        vector<int> flat(o, 0);
        cout << flat.size() << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout << (k + n*i + j) % o << ' '<< grid[i][j] << endl;

                flat[(k + n * i + j) % o] = grid[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                grid[i][j] = flat[n * i + j];
        }
        return grid;
    }
};