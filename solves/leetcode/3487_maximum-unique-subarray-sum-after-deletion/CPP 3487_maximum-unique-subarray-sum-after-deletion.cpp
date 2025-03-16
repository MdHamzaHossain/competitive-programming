class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        set<int> uncs;
        int mn = 101;
        int mx = -101;
        for (auto n : nums)
        {
            if (n > 0)
                uncs.insert(n);
            mn = min(mn, n);
            mx = max(mx, n);
        }
        if (uncs.size() == 0)
            return mx;
        int sum = 0;
        for (auto n : uncs)
        {
            sum += n;
        }
        return sum;
    }
};