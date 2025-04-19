class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
            res += (long long)(lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1) - lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]));
        return res;
    }
};