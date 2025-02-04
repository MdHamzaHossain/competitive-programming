class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int res = 0;
        int sum = nums[0];

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] > nums[i])
            {
                sum += nums[i + 1];
            }
            else
            {
                res = max(res, sum);
                sum = nums[i + 1];
            }
        }
        // account for last one
        res = max(res, sum);
        return res;
    }
};