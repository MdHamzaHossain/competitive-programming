// TODO
class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> result(n);

        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < n; ++i)
        {
            valueToIndices[nums[i]].push_back(i);
        }

        for (auto &[value, indices] : valueToIndices)
        {
            int groupSize = indices.size();

            long long leftSum = 0;

            long long rightSum = -1LL * groupSize * indices[0];
            for (int index : indices)
            {
                rightSum += index;
            }

            for (int i = 0; i < groupSize; ++i)
            {

                result[indices[i]] = leftSum + rightSum;

                if (i + 1 < groupSize)
                {
                    int gap = indices[i + 1] - indices[i];

                    leftSum += gap * (i + 1);

                    rightSum -= gap * (groupSize - i - 1);
                }
            }
        }

        return result;
    }
};