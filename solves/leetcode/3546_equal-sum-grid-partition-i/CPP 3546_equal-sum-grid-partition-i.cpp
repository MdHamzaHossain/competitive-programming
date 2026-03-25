class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {

        long long int sum = 0;
        const int r = grid.size();
        const int c = grid[0].size();
        vector<long long> rowS;
        for (int i = 0; i < r; i++)
        {
            sum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
            rowS.push_back(sum);
        }
        if (sum & 1)
            return false;

        sum = sum / 2;

        for (int i = 0; i < r; i++)
        {
            if (rowS[i] == sum)
                return true;
            if (rowS[i] > sum)
                break;
        }
        long long sum2 = 0;
        for (int i = 0; i < c; i++)
        {

            for (int j = 0; j < r; j++)
            {
                sum2 += grid[j][i];
            }
            cout << sum2 << ' ' << sum << endl;
            if (sum2 == sum)
                return true;
            if (sum2 > sum)
                break;
        }

        return false;
    }
};