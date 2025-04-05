class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < 1 << nums.size(); ++i)
        {
            int t = 0;
            for (int j = 0; j < nums.size(); ++j)
                if (i >> j & 1)
                    t ^= nums[j];
            res += t;
        }
        return res;
    }
};