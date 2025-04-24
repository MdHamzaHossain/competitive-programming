class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        unordered_map<int, int> counter;

        for (int num : nums)
            counter[num] = 1;

        int uniques = counter.size();

        counter.clear();

        int res = 0;

        int l = 0, r = 0;
        while (r < nums.size())
        {
            counter[nums[r]]++;

            while (counter.size() == uniques)
            {
                res += nums.size() - r;

                if (--counter[nums[l]] == 0)
                    counter.erase(nums[l]);

                ++l;
            }
            ++r;
        }

        return res;
    }
};