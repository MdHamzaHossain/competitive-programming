class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
            res.push_back(vector<int>(i + 1, 1));

        for (int i = 2; i < numRows; i++)
            for (int j = 1; j < res[i].size() - 1; ++j)
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        return res;
    }
};
