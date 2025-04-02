class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long res = 0, diff = 0;
        int mx = 0;
        for (auto n : nums)
        {
            res = max(res, diff * n);
            diff = max(diff, 1LL * mx - n);
            mx = max(mx, n);
        }
        return res;
    }
};