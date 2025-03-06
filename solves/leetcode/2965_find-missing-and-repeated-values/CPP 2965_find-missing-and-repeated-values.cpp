class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        vector<int> tracker(n * n + 1);

        for (const vector<int> &row : grid)
            for (const int e : row)
                tracker[e]++;

        int rep = -1;
        int miss = -1;

        for (int i = 1; i <= n * n; ++i)
        {
            if (tracker[i] == 2)
                rep = i;
            if (tracker[i] == 0)
                miss = i;
        }
        vector<int> ans;
        ans.push_back(rep);
        ans.push_back(miss);
        return ans;
    }
};