#define ll long long
class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        const auto beg = nums.begin();
        const int sz = nums.size();
        const ll finalNum = nums[sz - 1];
        bool done = false;
        int res = 0;
        for (int i = 0; i < sz; i++)
        {
            const ll num = nums[i];
            const ll numK = num * k;
            int range = sz;
            if (numK <= finalNum)
            {
                range = upper_bound(beg + 1, nums.end(), numK) - beg;
            }
            res = max(res, res - i);
        }
        res = sz - res;
        return res;
    }
};