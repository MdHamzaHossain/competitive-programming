class Solution
{
public:
    int repeatedNTimes(const vector<int> &nums)
    {
        bitset<10000 + 2> cnt;
        for (auto e : nums)
            if (cnt[e])
                return e;
            else
                cnt[e] = 1;
        return 0;
    }
};