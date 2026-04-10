class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        vector<vector<int>> indice(101);
        unordered_set<int> uniq;
        for (int i = 0; i < nums.size(); i++)
        {
            indice[nums[i]].push_back(i);
            uniq.insert(nums[i]);
        }
        int diffSum = 200;
        for (auto &e : uniq)
        {
            vector<int> daVec = indice[e];
            int t = daVec.size();
            for (int j = 0; j < t - 2; j++)
            {
                diffSum = min(2 * daVec[j + 2] - 2 * daVec[j], diffSum);
            }
        }

        if (diffSum == 200)
            diffSum = -1;
        return diffSum;
    }
};