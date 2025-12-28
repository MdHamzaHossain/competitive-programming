class Solution
{
public:
    int countNegatives(const vector<vector<int>> &grid)
    {
        int negs = 0;
        const int m = grid.size();
        const int n = grid[0].size();
        int lastNeg = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            auto v = grid[i];
            for (int j = lastNeg - 1; j >= 0; j--)
            {
                if (v[j] < 0)
                {
                    negs += (m - i);
                    lastNeg = j;
                }
                else
                    break;
            }
        }
        return negs;
    }
};