class Solution
{
public:
    int largestAltitude(const vector<int> &gain)
    {
        int res = 0;
        int piv = 0;
        for (auto &e : gain)
        {
            piv += e;
            res = max(res, piv);
        }
        return res;
    }
};