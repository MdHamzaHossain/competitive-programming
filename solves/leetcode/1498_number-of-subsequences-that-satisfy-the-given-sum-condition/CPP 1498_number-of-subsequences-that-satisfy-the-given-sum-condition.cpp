class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());
        const int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> prevCount(n + 1);
        prevCount[0] = 1;
        for (int i = 1; i <= n; ++i)
            prevCount[i] = (prevCount[i - 1] * 2) % mod;

        int res = 0;

        for (int i = 0; i < n; ++i)
        {

            if (nums[i] * 2L > target)
                break;

            res = (res + prevCount[upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin() - 1 - i]) % mod;
        }

        return res;
    }
};