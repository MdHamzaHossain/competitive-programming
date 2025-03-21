class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes,
                                  vector<vector<string>> &ingredients,
                                  vector<string> &supplies)
    {
        vector<string> res;
        unordered_set<string> iGotSupplies(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> inDegrees;
        deque<string> dq1;
        for (int i = 0; i < recipes.size(); i++)
            for (auto &e : ingredients[i])
                if (!iGotSupplies.contains(e))
                {
                    graph[e].push_back(recipes[i]);
                    ++inDegrees[recipes[i]];
                }

        for (string &e : recipes)
            if (!inDegrees.contains(e))
                dq1.push_back(e);

        while (!dq1.empty())
        {
            const string u = dq1.front();
            dq1.pop_back();
            res.push_back(u);
            if (!graph.contains(u))
                continue;
            for (const string &v : graph[u])
                if (--inDegrees[v] == 0)
                    dq1.push_back(v);
        }

        return res;
    }
};