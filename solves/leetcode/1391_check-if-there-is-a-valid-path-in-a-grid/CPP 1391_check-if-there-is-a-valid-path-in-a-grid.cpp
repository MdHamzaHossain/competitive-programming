// TODO
class Solution
{
public:
    vector<int> parent;

    bool hasValidPath(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        parent.resize(rows * cols);
        for (int i = 0; i < parent.size(); ++i)
        {
            parent[i] = i;
        }

        auto connectLeft = [&](int row, int col)
        {
            if (col > 0 && (grid[row][col - 1] == 1 ||
                            grid[row][col - 1] == 4 ||
                            grid[row][col - 1] == 6))
            {
                parent[find(row * cols + col)] = find(row * cols + col - 1);
            }
        };

        auto connectRight = [&](int row, int col)
        {
            if (col < cols - 1 && (grid[row][col + 1] == 1 ||
                                   grid[row][col + 1] == 3 ||
                                   grid[row][col + 1] == 5))
            {
                parent[find(row * cols + col)] = find(row * cols + col + 1);
            }
        };

        auto connectUp = [&](int row, int col)
        {
            if (row > 0 && (grid[row - 1][col] == 2 ||
                            grid[row - 1][col] == 3 ||
                            grid[row - 1][col] == 4))
            {
                parent[find(row * cols + col)] = find((row - 1) * cols + col);
            }
        };

        auto connectDown = [&](int row, int col)
        {
            if (row < rows - 1 && (grid[row + 1][col] == 2 ||
                                   grid[row + 1][col] == 5 ||
                                   grid[row + 1][col] == 6))
            {
                parent[find(row * cols + col)] = find((row + 1) * cols + col);
            }
        };

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                int streetType = grid[row][col];

                if (streetType == 1)
                {
                    connectLeft(row, col);
                    connectRight(row, col);
                }

                else if (streetType == 2)
                {
                    connectUp(row, col);
                    connectDown(row, col);
                }

                else if (streetType == 3)
                {
                    connectLeft(row, col);
                    connectDown(row, col);
                }

                else if (streetType == 4)
                {
                    connectRight(row, col);
                    connectDown(row, col);
                }

                else if (streetType == 5)
                {
                    connectLeft(row, col);
                    connectUp(row, col);
                }

                else
                {
                    connectRight(row, col);
                    connectUp(row, col);
                }
            }
        }

        return find(0) == find(rows * cols - 1);
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};
