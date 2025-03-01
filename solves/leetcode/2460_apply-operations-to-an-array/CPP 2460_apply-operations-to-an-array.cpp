class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        vector<int> res;
        int i;
        for (i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0)
                continue;
            if (nums[i] == nums[i + 1])
            {
                res.push_back(nums[i] * 2);
                i++;
                continue;
            }
            res.push_back(nums[i]);
        }
        if (i != nums.size())
            res.push_back(nums[i]);
        while (res.size() != nums.size())
            res.push_back(0);
        return res;
    }
};