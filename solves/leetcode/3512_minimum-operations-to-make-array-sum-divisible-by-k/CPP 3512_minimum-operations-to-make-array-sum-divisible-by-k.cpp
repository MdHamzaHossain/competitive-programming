class Solution
{
public:
    int minOperations(const vector<int> &nums, const int k)
    {
        int s = 0;
        for (const int &e : nums)
        {
            s = (s + e) % k;
        }
        return s;
    }
};
