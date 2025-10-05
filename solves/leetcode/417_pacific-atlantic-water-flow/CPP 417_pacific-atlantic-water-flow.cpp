// TODO
class Solution
{
public:
    vector<vector<int>> heightsGrid;
    int rows;
    int cols;

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        rows = heights.size();
        cols = heights[0].size();
        this->heightsGrid = heights;

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        unordered_set<int> pacificVisited;
        unordered_set<int> atlanticVisited;

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {

                if (row == 0 || col == 0)
                {
                    int flatIndex = row * cols + col;
                    pacificVisited.insert(flatIndex);
                    pacificQueue.emplace(row, col);
                }

                if (row == rows - 1 || col == cols - 1)
                {
                    int flatIndex = row * cols + col;
                    atlanticVisited.insert(flatIndex);
                    atlanticQueue.emplace(row, col);
                }
            }
        }

        bfs(pacificQueue, pacificVisited);
        bfs(atlanticQueue, atlanticVisited);

        vector<vector<int>> result;
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                int flatIndex = row * cols + col;

                if (pacificVisited.count(flatIndex) && atlanticVisited.count(flatIndex))
                {
                    result.push_back({row, col});
                }
            }
        }

        return result;
    }

    void bfs(queue<pair<int, int>> &bfsQueue, unordered_set<int> &visited)
    {

        vector<int> directions = {-1, 0, 1, 0, -1};

        while (!bfsQueue.empty())
        {

            int levelSize = bfsQueue.size();
            for (int i = 0; i < levelSize; ++i)
            {
                auto currentCell = bfsQueue.front();
                bfsQueue.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nextRow = currentCell.first + directions[dir];
                    int nextCol = currentCell.second + directions[dir + 1];
                    int flatIndex = nextRow * cols + nextCol;

                    if (nextRow >= 0 && nextRow < rows &&
                        nextCol >= 0 && nextCol < cols &&
                        !visited.count(flatIndex) &&
                        heightsGrid[nextRow][nextCol] >= heightsGrid[currentCell.first][currentCell.second])
                    {

                        visited.insert(flatIndex);
                        bfsQueue.emplace(nextRow, nextCol);
                    }
                }
            }
        }
    }
};