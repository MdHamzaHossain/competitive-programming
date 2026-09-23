// TODO
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int targetSum = totalSum - x;

        unordered_map<int, int> prefixSumIndex = {{0, -1}};

        int maxLength = -1;
        int currentPrefixSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {

            currentPrefixSum += nums[i];

            if (prefixSumIndex.find(currentPrefixSum) == prefixSumIndex.end())
                prefixSumIndex[currentPrefixSum] = i;

            if (prefixSumIndex.find(currentPrefixSum - targetSum) != prefixSumIndex.end())

                maxLength = max(maxLength, i - prefixSumIndex[currentPrefixSum - targetSum]);
        }

        return maxLength == -1 ? -1 : n - maxLength;
    }
};
