class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int mn = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); i++)
            if (mn > nums[i])
                mn = nums[i];
            else
                maxDiff = max(maxDiff, nums[i] - mn);

        return maxDiff == 0 ? -1 : maxDiff;
    }
};