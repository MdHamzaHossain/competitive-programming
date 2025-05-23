class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long res = 0;
        int prev = -1;
        int minKTemp = -1;
        int maxKTemp = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < minK || nums[i] > maxK)
                prev = i;
            if (nums[i] == minK)
                minKTemp = i;
            if (nums[i] == maxK)
                maxKTemp = i;
            res += max(0, min(minKTemp, maxKTemp) - prev);
        }

        return res;
    }
};