class Solution
{
public:
    pair<int, int> dfs(int node, vector<bool> tracker, vector<vector<int>> graph)
    {
        tracker[node] = true;
        int verticesCount = 1;
        int edgesCount = graph[node].size();

        for (int neighbor : graph[node])
        {
            if (!tracker[neighbor])
            {
                auto [subtreeVertices, subtreeEdges] = dfs(neighbor, tracker, graph);
                verticesCount += subtreeVertices;
                edgesCount += subtreeEdges;
            }
        }
        return make_pair(verticesCount, edgesCount);
    };
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);
        vector<bool> tracker(n, false);

        for (auto &edge : edges)
        {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        };

        function<pair<int, int>(int)> dfs = [&](int node) -> pair<int, int>
        {
            tracker[node] = true;
            int verticesCount = 1;
            int edgesCount = graph[node].size();

            for (int neighbor : graph[node])
            {
                if (!tracker[neighbor])
                {
                    auto [subtreeVertices, subtreeEdges] = dfs(neighbor);
                    verticesCount += subtreeVertices;
                    edgesCount += subtreeEdges;
                }
            }
            return make_pair(verticesCount, edgesCount);
        };

        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!tracker[i])
            {
                auto [componentVertices, componentEdges] = dfs(i);
                // auto [componentVertices, componentEdges] = dfs(i, tracker, graph);
                if (componentVertices * (componentVertices - 1) == componentEdges)
                {
                    count++;
                }
            }
        }
        return count;
    }
};