// TODO
class Solution
{
public:
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int boardSize = board.size();
        const int MOD = 1e9 + 7;

        int maxScore[boardSize][boardSize];

        int pathCount[boardSize][boardSize];

        memset(maxScore, -1, sizeof(maxScore));
        memset(pathCount, 0, sizeof(pathCount));

        maxScore[boardSize - 1][boardSize - 1] = 0;
        pathCount[boardSize - 1][boardSize - 1] = 1;

        auto updateCell = [&](int i, int j, int prevX, int prevY)
        {
            if (prevX >= boardSize || prevY >= boardSize ||
                maxScore[prevX][prevY] == -1 ||
                board[i][j] == 'X' || board[i][j] == 'S')
            {
                return;
            }

            if (maxScore[prevX][prevY] > maxScore[i][j])
            {
                maxScore[i][j] = maxScore[prevX][prevY];
                pathCount[i][j] = pathCount[prevX][prevY];
            }

            else if (maxScore[prevX][prevY] == maxScore[i][j])
            {
                pathCount[i][j] = (pathCount[i][j] + pathCount[prevX][prevY]) % MOD;
            }
        };

        for (int i = boardSize - 1; i >= 0; --i)
        {
            for (int j = boardSize - 1; j >= 0; --j)
            {

                updateCell(i, j, i + 1, j);
                updateCell(i, j, i, j + 1);
                updateCell(i, j, i + 1, j + 1);

                if (maxScore[i][j] != -1)
                {
                    if (board[i][j] >= '0' && board[i][j] <= '9')
                    {
                        maxScore[i][j] += (board[i][j] - '0');
                    }
                }
            }
        }

        vector<int> result(2);
        if (maxScore[0][0] != -1)
        {
            result[0] = maxScore[0][0];
            result[1] = pathCount[0][0];
        }

        return result;
    }
};