class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long res = 0, diff = 0,
                  mx = 0;
        for (long long x : nums)
        {
            res = max(res, diff * x);
            diff = max(diff, 1LL * mx - x);
            mx = max(mx, x);
        }
        return res;
    }
};