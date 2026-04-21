// TODO
class Solution
{
public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> findRoot = [&](int x)
        {
            if (x == parent[x])
            {
                return x;
            }

            return parent[x] = findRoot(parent[x]);
        };

        for (auto &swap : allowedSwaps)
        {
            int root1 = findRoot(swap[0]);
            int root2 = findRoot(swap[1]);
            parent[root1] = root2;
        }

        unordered_map<int, unordered_map<int, int>> componentValueCount;
        for (int i = 0; i < n; ++i)
        {
            int root = findRoot(i);
            componentValueCount[root][source[i]]++;
        }

        int hammingDistance = 0;
        for (int i = 0; i < n; ++i)
        {
            int root = findRoot(i);

            if (--componentValueCount[root][target[i]] < 0)
            {
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
};
