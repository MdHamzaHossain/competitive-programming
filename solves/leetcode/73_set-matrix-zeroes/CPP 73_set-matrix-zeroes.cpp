class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rS = matrix.size(), cS = matrix[0].size();
        bool rZ = false, cZ = false;

        for (int col = 0; col < cS; ++col)
        {
            if (matrix[0][col] == 0)
            {
                rZ = true;
                break;
            }
        }

        for (int row = 0; row < rS; ++row)
            if (matrix[row][0] == 0)
            {
                cZ = true;
                break;
            }

        for (int row = 1; row < rS; ++row)
            for (int col = 1; col < cS; ++col)
                if (matrix[row][col] == 0)
                {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }

        for (int row = 1; row < rS; ++row)
            for (int col = 1; col < cS; ++col)
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                    matrix[row][col] = 0;

        if (rZ)
            for (int col = 0; col < cS; ++col)
                matrix[0][col] = 0;

        if (cZ)
            for (int row = 0; row < rS; ++row)
                matrix[row][0] = 0;
    }
};