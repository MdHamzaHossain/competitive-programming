class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        long long mx = -20000000000000000;
        vector<long long> mins(k, 20000000000000000);
        long long sum = 0;
        mins[k - 1] = 0;
        for (long long i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            mx = max(mx, sum - mins[i % k]);
            mins[i % k] = min(mins[i % k], sum);
        }
        return mx;
    }
};