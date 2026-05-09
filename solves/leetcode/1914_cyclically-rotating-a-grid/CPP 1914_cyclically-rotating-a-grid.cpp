// TODO
class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        auto rotateLayer = [&](int layer, int rotations)
        {
            vector<int> elements;

            for (int col = layer; col < cols - layer - 1; ++col)
            {
                elements.push_back(grid[layer][col]);
            }

            for (int row = layer; row < rows - layer - 1; ++row)
            {
                elements.push_back(grid[row][cols - layer - 1]);
            }

            for (int col = cols - layer - 1; col > layer; --col)
            {
                elements.push_back(grid[rows - layer - 1][col]);
            }

            for (int row = rows - layer - 1; row > layer; --row)
            {
                elements.push_back(grid[row][layer]);
            }

            int totalElements = elements.size();
            rotations %= totalElements;

            if (rotations == 0)
            {
                return;
            }

            int index = rotations;

            for (int col = layer; col < cols - layer - 1; ++col)
            {
                grid[layer][col] = elements[index % totalElements];
                index++;
            }

            for (int row = layer; row < rows - layer - 1; ++row)
            {
                grid[row][cols - layer - 1] = elements[index % totalElements];
                index++;
            }

            for (int col = cols - layer - 1; col > layer; --col)
            {
                grid[rows - layer - 1][col] = elements[index % totalElements];
                index++;
            }

            for (int row = rows - layer - 1; row > layer; --row)
            {
                grid[row][layer] = elements[index % totalElements];
                index++;
            }
        };

        int totalLayers = min(rows, cols) / 2;
        for (int layer = 0; layer < totalLayers; ++layer)
        {
            rotateLayer(layer, k);
        }

        return grid;
    }
};