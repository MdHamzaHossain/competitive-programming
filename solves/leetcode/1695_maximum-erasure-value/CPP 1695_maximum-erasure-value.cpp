class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int mx = 0;
        int cnt = 0;
        unordered_set<int> seen;

        for (int l = 0, r = 0; r < nums.size(); ++r)
        {
            while (!seen.insert(nums[r]).second)
            {
                cnt -= nums[l];
                seen.erase(nums[l++]);
            }
            cnt += nums[r];
            mx = max(mx, cnt);
        }

        return mx;
    }
};