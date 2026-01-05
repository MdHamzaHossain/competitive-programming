class Solution
{
public:
    long long maxMatrixSum(const vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        long long sum = 0;
        bool negs = 0;
        int mn = abs(matrix[0][0]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                const int num = matrix[i][j];
                if (matrix[i][j] < 0)
                    negs = !negs;
                const int t = abs(num);
                sum += t;
                mn = min(mn, t);
            }
        }
        if (negs)
            sum -= 2 * mn;
        return sum;
    }
};