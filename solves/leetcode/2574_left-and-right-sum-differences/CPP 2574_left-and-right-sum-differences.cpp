class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        long long sum = 0;
        const int n = nums.size();
        vector<int> res(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            res[i + 1] = sum;
            sum += nums[i];
        }
        sum = 0;
        for (int i = n; i > 0; i--)
        {
            res[i] = abs(res[i] - sum);
            sum += nums[i - 1];
        }
        res.erase(res.begin());
        nums[0] = abs(nums[0] - sum);
        return res;
    }
};