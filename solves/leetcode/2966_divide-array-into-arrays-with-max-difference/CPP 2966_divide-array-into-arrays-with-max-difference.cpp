class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i += 3)
        {
            if (i + 2 >= nums.size())
                return {};

            vector<int> curr = {nums[i], nums[i + 1], nums[i + 2]};

            if (curr[2] - curr[0] > k)
                return {};

            ans.emplace_back(curr);
        }

        return ans;
    }
};
