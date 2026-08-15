// TODO
class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int xo = nums[0], n = nums.size();
        for (int i = 1; i < n; i++)
            xo ^= nums[i];
        if (xo != 0)
            return n;

        int count = 0;
        for (int &num : nums)
        {
            if (num == 0)
                count++;
        }
        return count == n ? 0 : n - 1;
    }
};