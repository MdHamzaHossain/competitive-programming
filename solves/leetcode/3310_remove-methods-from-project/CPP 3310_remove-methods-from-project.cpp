// TODO
class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {

        vector<bool> isSuspicious(n, false);

        vector<bool> visited(n, false);

        vector<vector<int>> undirectedGraph(n);
        vector<vector<int>> directedGraph(n);

        for (const auto &invocation : invocations)
        {
            int caller = invocation[0];
            int callee = invocation[1];

            undirectedGraph[caller].push_back(callee);
            undirectedGraph[callee].push_back(caller);

            directedGraph[caller].push_back(callee);
        }

        auto markSuspiciousFromBuggy = [&](this auto &&markSuspiciousFromBuggy, int currentMethod) -> void
        {
            isSuspicious[currentMethod] = true;

            for (int calledMethod : directedGraph[currentMethod])
            {
                if (!isSuspicious[calledMethod])
                {
                    markSuspiciousFromBuggy(calledMethod);
                }
            }
        };

        markSuspiciousFromBuggy(k);

        auto markConnectedAsNonRemovable = [&](this auto &&markConnectedAsNonRemovable, int currentMethod) -> void
        {
            visited[currentMethod] = true;

            for (int connectedMethod : undirectedGraph[currentMethod])
            {
                if (!visited[connectedMethod])
                {

                    isSuspicious[connectedMethod] = false;
                    markConnectedAsNonRemovable(connectedMethod);
                }
            }
        };

        for (int methodId = 0; methodId < n; ++methodId)
        {
            if (!isSuspicious[methodId] && !visited[methodId])
            {
                markConnectedAsNonRemovable(methodId);
            }
        }

        vector<int> remainingMethodsList;
        for (int methodId = 0; methodId < n; ++methodId)
        {
            if (!isSuspicious[methodId])
            {
                remainingMethodsList.push_back(methodId);
            }
        }

        return remainingMethodsList;
    }
};