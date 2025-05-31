// TODO
class Solution
{
public:
    int boardSize;

    int snakesAndLadders(vector<vector<int>> &board)
    {
        boardSize = board.size();
        queue<int> positionsQueue;
        positionsQueue.push(1);
        vector<bool> visited(boardSize * boardSize + 1, false);
        visited[1] = true;
        int moves = 0;

        while (!positionsQueue.empty())
        {
            int levelSize = positionsQueue.size();
            for (int i = 0; i < levelSize; ++i)
            {
                int current = positionsQueue.front();
                positionsQueue.pop();

                if (current == boardSize * boardSize)
                    return moves;

                for (int nextPos = current + 1; nextPos <= min(current + 6, boardSize * boardSize); ++nextPos)
                {
                    auto position = convertTo2D(nextPos);
                    int target = nextPos;
                    int row = position.first, col = position.second;

                    if (board[row][col] != -1)
                        target = board[row][col];

                    if (!visited[target])
                    {
                        visited[target] = true;
                        positionsQueue.push(target);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }

    pair<int, int> convertTo2D(int pos)
    {
        int row = (pos - 1) / boardSize;
        int col = (pos - 1) % boardSize;
        if (row % 2 == 1)
            col = boardSize - 1 - col;

        row = boardSize - 1 - row;
        return {row, col};
    }
};