//TODO
class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
        {
                int rS = mat.size(), cS = mat[0].size();
                        vector<vector<int>> width(rS, vector<int>(cS, 0));

                                for (int row = 0; row < rS; ++row)
                                        {
                                                    for (int col = 0; col < cS; ++col)
                                                                    if (mat[row][col] == 1)
                                                                                        width[row][col] = col == 0 ? 1 : 1 + width[row][col - 1];
                                                                                                }

                                                                                                        int cnt = 0;

                                                                                                                for (int topRow = 0; topRow < rS; ++topRow)
                                                                                                                        {
                                                                                                                                    for (int col = 0; col < cS; ++col)
                                                                                                                                                {
                                                                                                                                                                int minWidth = INT_MAX;

                                                                                                                                                                                for (int bottomRow = topRow; bottomRow >= 0 && minWidth > 0; --bottomRow)
                                                                                                                                                                                                {
                                                                                                                                                                                                                    minWidth = min(minWidth, width[bottomRow][col]);
                                                                                                                                                                                                                                        cnt += minWidth;
                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                            }

                                                                                                                                                                                                                                                                                    return cnt;
                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                        };