class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0, 1});

        while (!pq.empty())
        {
            auto top = pq.top();

            int time = top[0];
            int x = top[1];
            int y = top[2];
            int parity = top[3];

            pq.pop();

            moveTime[x][y] = -1;

            if (x == n - 1 && y == m - 1)
                return time;

            for (int d = 0; d < 4; d++)
            {

                if ((x + dx[d]) < 0 || (y + dy[d]) < 0 || (x + dx[d]) >= n || (y + dy[d]) >= m || moveTime[(x + dx[d])][(y + dy[d])] == -1)
                    continue;

                int timeN = max(moveTime[(x + dx[d])][(y + dy[d])], time);

                if (dist[(x + dx[d])][(y + dy[d])] > timeN + parity)
                {
                    dist[(x + dx[d])][(y + dy[d])] = timeN + parity;
                    pq.push({dist[(x + dx[d])][(y + dy[d])], (x + dx[d]), (y + dy[d]), (parity == 1) ? 2 : 1});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};