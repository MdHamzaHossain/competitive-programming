// TODO
class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long a = 0, b = -1061109567;
        for (int x : nums)
        {
            long long t = a;
            a = max(a + x, b + (x ^ k));
            b = max(b + x, t + (x ^ k));
        }
        return a;
    }
};