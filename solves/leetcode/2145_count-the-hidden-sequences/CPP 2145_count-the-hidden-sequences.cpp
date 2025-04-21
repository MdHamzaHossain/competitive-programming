class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long sum = 0;
        long mn = 0;
        long mx = 0;

        for (auto e : differences)
        {
            sum += e;
            mn = min(mn, sum);
            mx = max(mx, sum);
        }

        return max(0L, (upper - lower) - (mx - mn) + 1);
    }
};