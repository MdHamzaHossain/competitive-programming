class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int mx = ranges::max(nums);
        long res = 0;
        int cnt = 0;

        for (int l = 0, r = 0; r < nums.size(); ++r)
        {
            if (nums[r] == mx)
                cnt++;
            while (cnt == k)
                cnt -= (nums[l++] == mx);
            res += l;
        }

        return res;
    }
};