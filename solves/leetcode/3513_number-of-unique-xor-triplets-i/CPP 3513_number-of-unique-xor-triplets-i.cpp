class Solution
{
public:
    int uniqueXorTriplets(const vector<int> &nums)
    {
        const int n = nums.size();
        if (n < 3)
            return n;
        return 1 << (1 + (int)log2(n));
    }
};