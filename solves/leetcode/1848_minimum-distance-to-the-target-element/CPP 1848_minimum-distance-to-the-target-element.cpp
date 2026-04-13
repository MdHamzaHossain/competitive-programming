class Solution
{
public:
    int getMinDistance(const vector<int> &nums, const int target, const int start)
    {
        const int n = nums.size();
        int mn = n + 3;
        for (int i = 0; i < n; i++)
        {
            const auto e = nums[i];
            if (e == target)
                mn = min(mn, abs(start - i));
        }
        return mn;
    }
};