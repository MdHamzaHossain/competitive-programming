class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> indice;
        for (int i = 0; i < nums.size(); i++)
        {
            indice[nums[i]].push_back(i);
        }
        int diffSum = 200046;
        for (auto const &[k, daVec] : indice)
        {
            int t = daVec.size();
            for (int j = 0; j < t - 2; j++)
            {
                diffSum = min(2 * daVec[j + 2] - 2 * daVec[j], diffSum);
            }
        }

        if (diffSum == 200046)
            diffSum = -1;
        return diffSum;
    }
};