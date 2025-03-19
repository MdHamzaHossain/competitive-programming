class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int res = 0;

        for (int i = 0; i + 2 < nums.size(); ++i)
            if (nums[i] == 0)
            {
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                res++;
            }

        return nums[nums.size() - 1] == 0 || nums[nums.size() - 2] == 0 ? -1 : res;
    }
};