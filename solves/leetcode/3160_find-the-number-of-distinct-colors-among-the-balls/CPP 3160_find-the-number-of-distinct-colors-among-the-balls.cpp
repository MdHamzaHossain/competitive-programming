class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        map<int, int> graph;
        map<int, int> tracker;
        vector<int> res;
        for (auto e : queries)
        {
            int k = e[0];
            int v = e[1];
            tracker[v]++;
            if (graph.contains(k) && --tracker[graph[k]] == 0)
                tracker.erase(graph[k]);
            graph[k] = v;
            res.push_back(tracker.size());
        }
        return res;
    }
};