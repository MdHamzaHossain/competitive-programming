class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        if (*(nums.end() - 1) != n - 1)
        {
            return false;
        }
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] != i)
                return false;
        }
        return true;
    }
};