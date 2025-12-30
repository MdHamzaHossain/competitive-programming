#define FORN(i, a, b) for (int i = a; i < b; i++)
class Solution
{
public:
    int numMagicSquaresInside(const vector<vector<int>> &grid)
    {
        const int r = grid.size();
        const int c = grid[0].size();
        int res = 0;
        const unordered_set<long long> squares = {276951438LL,
                                                  294753618LL,
                                                  438951276LL,
                                                  492357816LL,
                                                  618753294LL,
                                                  672159834LL,
                                                  816357492LL,
                                                  834159672LL};
        FORN(i, 0, r - 2)
        {
            FORN(j, 0, c - 2)
            {
                if (grid[i + 1][j + 1] == 5)
                {
                    long long tem = 0;
                    FORN(mR, i, i + 3)
                    {
                        FORN(mC, j, j + 3)
                        {
                            tem = tem * 10 + grid[mR][mC];
                        }
                    }
                    if (squares.count(tem))
                        res++;
                }
            }
        }
        return res;
    }
};