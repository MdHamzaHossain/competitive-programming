typedef long long ll;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const ll INF = LLONG_MAX / 2;
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, ll>>> graph(n);
        vector<ll> dists(n, INF);
        vector<ll> paths(n, 0);
        vector<bool> tracker(n, false);

        for (auto &road : roads)
        {
            int u = road[0], v = road[1];
            ll t = road[2];
            graph[u].emplace_back(v, t);
            graph[v].emplace_back(u, t);
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        dists[0] = 0;
        paths[0] = 1;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [distance, u] = pq.top();
            pq.pop();
            if (tracker[u])
                continue;
            tracker[u] = true;

            for (auto &[v, t] : graph[u])
            {
                ll nextDistance = dists[u] + t;
                if (dists[v] > nextDistance)
                {
                    dists[v] = nextDistance;
                    paths[v] = paths[u];
                    pq.push({nextDistance, v});
                }
                else if (dists[v] == nextDistance)
                    paths[v] = (paths[v] + paths[u]) % MOD;
            }
        }
        return paths[n - 1];
    }
};
