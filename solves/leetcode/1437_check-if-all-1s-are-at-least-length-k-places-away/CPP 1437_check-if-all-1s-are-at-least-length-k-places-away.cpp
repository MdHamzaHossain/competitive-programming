class Solution
{
public:
    bool kLengthApart(const vector<int> &nums, const int k)
    {
        int prev = -k - 2;
        const int n = nums.size();
        int i = 0;
        for (const int &n : nums)
        {
            if (n == 1)
            {
                if (i - prev - 1 < k)
                    return false;
                prev = i;
            }
            i++;
        }
        return true;
    }
};