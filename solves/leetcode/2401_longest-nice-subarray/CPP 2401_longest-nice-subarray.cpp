class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int res = 0;
        int pos = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            while (pos & nums[j])
                pos ^= nums[i++];

            res = max(j - i + 1, res);
            pos |= nums[j];
        }

        return res;
    }
};