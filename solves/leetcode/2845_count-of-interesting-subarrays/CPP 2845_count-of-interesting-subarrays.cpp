class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        vector<int> tracker(nums.size());
        for (int i = 0; i < nums.size(); i++)
            tracker[i] = int(nums[i] % modulo == k);

        unordered_map<int, int> cnt;
        cnt[0] = 1;
        long long res = 0;
        int sum = 0;
        for (auto x : tracker)
        {
            sum += x;
            res += cnt[(sum - k + modulo) % modulo];
            cnt[sum % modulo]++;
        }
        return res;
    }
};