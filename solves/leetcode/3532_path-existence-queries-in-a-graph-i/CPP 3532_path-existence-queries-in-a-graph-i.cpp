// TODO
class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {

        vector<int> componentId(n);

        int componentCount = 0;

        for (int i = 1; i < n; ++i)
        {

            if (nums[i] - nums[i - 1] > maxDiff)
            {

                ++componentCount;
            }

            componentId[i] = componentCount;
        }

        vector<bool> result;

        for (const auto &query : queries)
        {
            int startIndex = query[0];
            int endIndex = query[1];

            result.push_back(componentId[startIndex] == componentId[endIndex]);
        }

        return result;
    }
};