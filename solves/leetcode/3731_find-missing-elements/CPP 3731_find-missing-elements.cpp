class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        bitset<101> bSet;
        int mn = 101;
        int mx = 0;
        for (auto &e : nums)
        {
            mn = min(mn, e);
            mx = max(mx, e);
            bSet[e] = 1;
        }
        vector<int> res;
        for (int i = mn; i <= mx; i++)
        {
            if (!bSet[i])
                res.push_back(i);
        }
        return res;
    }
};