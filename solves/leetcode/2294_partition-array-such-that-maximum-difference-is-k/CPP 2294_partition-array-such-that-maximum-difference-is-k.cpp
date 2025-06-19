class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int res = 1;
        int curr = nums[0];

        for (int &e : nums)
        {
            if (e - curr > k)
            {
                curr = e;
                res++;
            }
        }

        return res;
    }
};