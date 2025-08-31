// TODO
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {

        bool rTr[9][9] = {false};
        bool cTr[9][9] = {false};
        bool blockTr[3][3][9] = {false};
        bool valid = false;
        vector<pair<int, int>> empties;
        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                if (board[r][c] == '.')
                    empties.push_back({r, c});
                else
                {
                    int n = board[r][c] - '1';
                    rTr[r][n] = true;
                    cTr[c][n] = true;
                    blockTr[r / 3][c / 3][n] = true;
                }
            }
        }

        function<void(int)> backtrack = [&](int cellIndex)
        {
            if (cellIndex == empties.size())
            {
                valid = true;
                return;
            }

            int currR = empties[cellIndex].first;
            int currC = empties[cellIndex].second;
            int bRow = currR / 3;
            int bCol = currC / 3;

            for (int digit = 0; digit < 9; ++digit)
            {

                if (!rTr[currR][digit] &&
                    !cTr[currC][digit] &&
                    !blockTr[bRow][bCol][digit])
                {

                    rTr[currR][digit] = true;
                    cTr[currC][digit] = true;
                    blockTr[bRow][bCol][digit] = true;
                    board[currR][currC] = digit + '1';

                    backtrack(cellIndex + 1);

                    if (valid)
                        return;

                    rTr[currR][digit] = false;
                    cTr[currC][digit] = false;
                    blockTr[bRow][bCol][digit] = false;
                }
            }
        };

        backtrack(0);
    }
};