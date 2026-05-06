// TODO
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int ROWS = boxGrid.size(), COLS = boxGrid[0].size();

        for (int r = ROWS - 1; r >= 0; r--)
        {
            for (int c1 = COLS - 1; c1 >= 0; c1--)
            {
                if (boxGrid[r][c1] == '#')
                {
                    int c2 = c1 + 1;
                    while (c2 < COLS && boxGrid[r][c2] == '.')
                    {
                        c2++;
                    }
                    boxGrid[r][c1] = '.';
                    boxGrid[r][c2 - 1] = '#';
                }
            }
        }

        vector<vector<char>> res(COLS, vector<char>(ROWS));
        for (int c = 0; c < COLS; c++)
        {
            for (int r = ROWS - 1; r >= 0; r--)
            {
                res[c][ROWS - 1 - r] = boxGrid[r][c];
            }
        }
        return res;
    }
};