class Solution
{
public:
    int minimizeMax(vector<int> &nums, int pairsToRemove)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0] + 1;
        auto check = [&](int diff) -> bool
        {
            int pairsCount = 0;

            for (int i = 0; i < n - 1; ++i)
                if (nums[i + 1] - nums[i] <= diff)
                {
                    pairsCount++;
                    i++;
                }

            return pairsCount >= pairsToRemove;
        };

        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};