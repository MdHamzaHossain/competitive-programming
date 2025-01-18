class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> crossed(r, vector<bool>(c, false));
        vector<vector<int>> directions = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        deque<pair<int, int>> dq = {{0, 0}};

        while (dq.size())
        {
            auto temp = dq.front();
            dq.pop_front();

            int currR = temp.first / c;
            int currC = temp.first % c;
            int cost = temp.second;
            if (currR == (r - 1) && currC == (c - 1))
                return cost;
            if (crossed[currR][currC])
                continue;
            crossed[currR][currC] = true;

            for (int j = 1; j <= 4; j++)
            {
                int nextR = currR + directions[j][0];
                int nextC = currC + directions[j][1];

                if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c)
                {
                    int i = nextR * c + nextC;
                    if (grid[currR][currC] == j)
                    {
                        dq.push_front({i, cost});
                    }
                    else
                    {
                        dq.push_back({i, cost + 1});
                    }
                }
            }
        }
        return -1;
    }
};