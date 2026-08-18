// TODO
class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {

        if (k == 1)
        {
            unordered_map<int, int> frequencyMap;

            for (int num : nums)
            {
                ++frequencyMap[num];
            }

            int maxUniqueValue = -1;

            for (const auto &[value, frequency] : frequencyMap)
            {
                if (frequency == 1)
                {
                    maxUniqueValue = max(maxUniqueValue, value);
                }
            }

            return maxUniqueValue;
        }

        int arraySize = nums.size();

        if (k == arraySize)
        {
            return ranges::max(nums);
        }

        auto getValueIfUnique = [&](int targetIndex) -> int
        {
            for (int i = 0; i < arraySize; ++i)
            {

                if (i != targetIndex && nums[i] == nums[targetIndex])
                {
                    return -1;
                }
            }

            return nums[targetIndex];
        };

        return max(getValueIfUnique(0), getValueIfUnique(arraySize - 1));
    }
};