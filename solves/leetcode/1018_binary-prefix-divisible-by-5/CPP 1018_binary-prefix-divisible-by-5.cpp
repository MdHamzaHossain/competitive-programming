// TODO
class Solution
{
public:
    vector<bool> prefixesDivBy5(const vector<int> &nums)
    {
        vector<bool> res(nums.size());
        int curr = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            curr = ((curr << 1) | nums[i]) % 5;
            res[i] = curr == 0;
        }

        return res;
    }
};