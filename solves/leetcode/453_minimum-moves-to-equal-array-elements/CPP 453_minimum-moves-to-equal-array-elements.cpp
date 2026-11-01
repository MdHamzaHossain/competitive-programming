class Solution
{
public:
    int minMoves(const vector<int> &nums)
    {
        const int mn = *min_element(nums.begin(), nums.end());
        long long c = 0;
        for (auto &e : nums)
        {
            c += abs(e - mn);
        }
        return c;
    }
};