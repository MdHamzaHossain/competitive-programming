// holy... what
class Solution
{
public:
    const int dirs[5] = {-1, 0, 1, 0, -1};

    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int querySize = queries.size();
        vector<pair<int, int>> sortedQueries(querySize);
        for (int i = 0; i < querySize; ++i)
            sortedQueries[i] = {queries[i], i};
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> answer(querySize);
        int rows = grid.size(), cols = grid[0].size();
        bool tracker[rows][cols];
        memset(tracker, 0, sizeof tracker);

        tracker[0][0] = true;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        minHeap.push({grid[0][0], 0, 0});

        int exploredCount = 0;

        for (auto &queryPair : sortedQueries)
        {

            while (!minHeap.empty() && get<0>(minHeap.top()) < queryPair.first)
            {
                auto [value, row, col] = minHeap.top();
                minHeap.pop();
                exploredCount++;

                for (int i = 0; i < 4; ++i)
                {
                    int newRow = row + dirs[i], newCol = col + dirs[i + 1];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !tracker[newRow][newCol])
                    {
                        tracker[newRow][newCol] = true;
                        minHeap.push({grid[newRow][newCol], newRow, newCol});
                    }
                }
            }
            answer[queryPair.second] = exploredCount;
        }

        return answer;
    }
};
