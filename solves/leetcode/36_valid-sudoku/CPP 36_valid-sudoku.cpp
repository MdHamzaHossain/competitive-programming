// TODO
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> rS(9, vector<bool>(9, false));
        vector<vector<bool>> cS(9, vector<bool>(9, false));
        vector<vector<bool>> sB(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char curr = board[i][j];

                if (curr == '.')
                    continue;

                int ind = curr - '0' - 1;
                int boxInd = (i / 3) * 3 + (j / 3);
                if (rS[i][ind] || cS[j][ind] || sB[boxInd][ind])
                    return false;

                rS[i][ind] = true;
                cS[j][ind] = true;
                sB[boxInd][ind] = true;
            }
        }

        return true;
    }
};