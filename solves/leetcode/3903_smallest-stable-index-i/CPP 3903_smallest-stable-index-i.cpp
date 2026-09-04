class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        const int n = nums.size();
        vector<int> mxS(n);
        vector<int> mnS(n);

        int mx = 0, mn = 1e9 + 2;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            const int j = n - 1 - i;
            mn = min(mn, nums[j]);
            mxS[i] = mx;
            mnS[j] = mn;
        }
        int res = 1e9 + 2;
        for (int i = 0; i < n; i++)
        {
            res = min(mxS[i] - mnS[i], res);
            if (res <= k)
                return i;
        }
        return -1;
    }
};