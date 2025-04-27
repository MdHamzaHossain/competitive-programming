class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int res = 0;
        for (int i = 1; i + 1 < nums.size(); i++)
            res += (nums[i - 1] + nums[i + 1]) * 2 == nums[i];
        return res;
    }
};