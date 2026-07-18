class Solution
{
public:
    int findGCD(const vector<int> &nums)
    {
        int mx = 0;
        int mn = 1001;
        for (auto &e : nums)
        {
            mx = max(mx, e);
            mn = min(mn, e);
        }
        return __gcd(mn, mx);
    }
};