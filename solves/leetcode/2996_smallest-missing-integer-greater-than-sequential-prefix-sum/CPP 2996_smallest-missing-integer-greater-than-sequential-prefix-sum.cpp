// TODO
class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {

        int prefixSum = nums[0];

        for (int i = 1; i < nums.size() && nums[i] == nums[i - 1] + 1; ++i)
        {
            prefixSum += nums[i];
        }

        bitset<51> isPresent;

        for (int num : nums)
        {
            isPresent[num] = 1;
        }

        for (int candidate = prefixSum;; ++candidate)
        {

            if (candidate >= 51 || !isPresent[candidate])
            {
                return candidate;
            }
        }
    }
};
