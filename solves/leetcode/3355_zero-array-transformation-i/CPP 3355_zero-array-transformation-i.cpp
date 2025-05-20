class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> tracker(nums.size() + 1);
        int t = 0;

        for (const vector<int> &query : queries)
        {
            tracker[query[0]]++;
            tracker[query[1] + 1]--;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            t += tracker[i];
            if (t < nums[i])
                return false;
        }

        return true;
    }
};