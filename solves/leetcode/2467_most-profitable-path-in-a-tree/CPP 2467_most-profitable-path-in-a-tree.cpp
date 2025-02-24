
class Solution
{
public:
    void dfs(const vector<vector<int>> &treeGraph, int u, int prev, int d,
             vector<int> &parentTracker, vector<int> &dist)
    {
        parentTracker[u] = prev;
        dist[u] = d;
        for (const int v : treeGraph[u])
        {
            if (dist[v] == -1)
                dfs(treeGraph, v, u, d + 1, parentTracker, dist);
        }
    }

    int getMoney(const vector<vector<int>> &treeGraph, int u, int prev,
                 const vector<int> &amount)
    {
        if (treeGraph[u].size() == 1 && treeGraph[u][0] == prev)
            return amount[u];

        int mx = INT_MIN;
        for (const int v : treeGraph[u])
            if (v != prev)
                mx = max(mx, getMoney(treeGraph, v, u, amount));

        return amount[u] + mx;
    }
    int mostProfitablePath(vector<vector<int>> &edges, int bob,
                           vector<int> &amount)
    {
        const int n = amount.size();
        vector<vector<int>> treeGraph(n);
        vector<int> parentTracker(n);
        vector<int> aliceMoves(n, -1);

        for (const vector<int> &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            treeGraph[u].push_back(v);
            treeGraph[v].push_back(u);
        }

        dfs(treeGraph, 0, -1, 0, parentTracker, aliceMoves);

        for (int u = bob, bobMoves = 0; u != 0; u = parentTracker[u], ++bobMoves)
            if (bobMoves < aliceMoves[u])
                amount[u] = 0;
            else if (bobMoves == aliceMoves[u])
                amount[u] /= 2;

        return getMoney(treeGraph, 0, -1, amount);
    }
};