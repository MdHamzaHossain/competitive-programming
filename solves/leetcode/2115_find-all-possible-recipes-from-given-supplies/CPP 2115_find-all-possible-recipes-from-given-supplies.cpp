class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> degs;

        for (int i = 0; i < recipes.size(); ++i)
        {
            for (const auto &e : ingredients[i])
                graph[e].push_back(recipes[i]);
            degs[recipes[i]] = ingredients[i].size();
        }

        queue<string> q;
        for (const auto &supply : supplies)
            q.push(supply);

        vector<string> res;

        while (!q.empty())
        {
            int queueSize = q.size();
            while (queueSize--)
            {
                string fir = q.front();
                q.pop();

                for (const auto &recipe : graph[fir])
                {
                    if (--degs[recipe] == 0)
                    {
                        res.push_back(recipe);
                        q.push(recipe);
                    }
                }
            }
        }

        return res;
    }
};