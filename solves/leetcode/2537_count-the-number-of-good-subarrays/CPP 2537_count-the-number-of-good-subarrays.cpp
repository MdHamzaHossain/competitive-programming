class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        unordered_map<int, int> counter;
        long long total = 0;
        long long curr = 0;
        int ind = 0;

        for (int &num : nums)
        {
            curr += counter[num]++;

            while (curr - counter[nums[ind]] + 1 >= k)
                curr -= --counter[nums[ind++]];

            if (curr >= k)
                total += ind + 1;
        }

        return total;
    }
};