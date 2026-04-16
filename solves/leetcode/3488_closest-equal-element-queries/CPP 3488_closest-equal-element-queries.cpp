// TODO
// TODO
class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        int arraySize = nums.size();
        int doubledSize = arraySize * 2;

        vector<int> minDistances(doubledSize, doubledSize);

        unordered_map<int, int> lastSeenIndex;
        for (int i = 0; i < doubledSize; i++)
        {
            int currentValue = nums[i % arraySize];

            if (lastSeenIndex.count(currentValue))
            {
                minDistances[i] = min(minDistances[i], i - lastSeenIndex[currentValue]);
            }

            lastSeenIndex[currentValue] = i;
        }

        unordered_map<int, int> nextSeenIndex;
        for (int i = doubledSize - 1; i >= 0; i--)
        {
            int currentValue = nums[i % arraySize];

            if (nextSeenIndex.count(currentValue))
            {
                minDistances[i] = min(minDistances[i], nextSeenIndex[currentValue] - i);
            }

            nextSeenIndex[currentValue] = i;
        }

        for (int i = 0; i < arraySize; i++)
        {
            minDistances[i] = min(minDistances[i], minDistances[i + arraySize]);
        }

        vector<int> result;
        for (int queryIndex : queries)
        {

            result.push_back(minDistances[queryIndex] >= arraySize ? -1 : minDistances[queryIndex]);
        }

        return result;
    }
};