class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        sort(nums.begin() + 1, nums.end());
        int s = 0;
        for (int i = 0; i < 3; i++)
            s += nums[i];
        return s;
    }
};