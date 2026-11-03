class Solution
{
public:
    int minMoves(const vector<int> &nums)
    {
        const int mx = *max_element(nums.begin(), nums.end());
        int res = 0;
        for (auto &e : nums)
            res += mx - e;
        return res;
    }
};