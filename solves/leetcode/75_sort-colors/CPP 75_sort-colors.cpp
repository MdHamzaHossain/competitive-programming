class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = -1, r = nums.size(), curr = 0;

        while (curr < r)
        {
            if (nums[curr] == 0)
                swap(nums[++l], nums[curr++]);
            else if (nums[curr] == 2)
                swap(nums[--r], nums[curr]);
            else
                ++curr;
        }
    }
};
