// TODO
class Solution
{
public:
    vector<vector<int>> graphify(const vector<vector<int>> &edges)
    {
        int numNodes = edges.size() + 1;
        vector<vector<int>> graph(numNodes);

        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    int dfs(const vector<vector<int>> &graph, int currentNode, int parentNode, int stepsRemaining)
    {

        if (stepsRemaining < 0)
            return 0;

        int count = 1;

        for (int neighbor : graph[currentNode])
            if (neighbor != parentNode)
                count += dfs(graph, neighbor, currentNode, stepsRemaining - 1);

        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {

        auto graph2 = graphify(edges2);
        int size2 = edges2.size() + 1;
        int maxTargets = 0;

        for (int node = 0; node < size2; node++)
            maxTargets = max(maxTargets, dfs(graph2, node, -1, k - 1));

        auto graph1 = graphify(edges1);
        int size1 = edges1.size() + 1;

        vector<int> result(size1, maxTargets);

        for (int node = 0; node < size1; ++node)
            result[node] += dfs(graph1, node, -1, k);

        return result;
    }
};