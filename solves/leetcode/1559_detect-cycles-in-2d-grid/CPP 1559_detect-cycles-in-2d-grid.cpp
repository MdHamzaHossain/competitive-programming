// TODO
class Solution
{
public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        const vector<int> directions = {-1, 0, 1, 0, -1};

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {

                if (!visited[row][col])
                {

                    queue<array<int, 4>> bfsQueue;
                    bfsQueue.push({row, col, -1, -1});
                    visited[row][col] = true;

                    while (!bfsQueue.empty())
                    {
                        auto current = bfsQueue.front();
                        bfsQueue.pop();

                        int currentRow = current[0];
                        int currentCol = current[1];
                        int parentRow = current[2];
                        int parentCol = current[3];

                        for (int dir = 0; dir < 4; ++dir)
                        {
                            int nextRow = currentRow + directions[dir];
                            int nextCol = currentCol + directions[dir + 1];

                            if (nextRow >= 0 && nextRow < rows &&
                                nextCol >= 0 && nextCol < cols)
                            {

                                if (grid[nextRow][nextCol] != grid[currentRow][currentCol] ||
                                    (nextRow == parentRow && nextCol == parentCol))
                                {
                                    continue;
                                }

                                if (visited[nextRow][nextCol])
                                {
                                    return true;
                                }

                                bfsQueue.push({nextRow, nextCol, currentRow, currentCol});
                                visited[nextRow][nextCol] = true;
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};
