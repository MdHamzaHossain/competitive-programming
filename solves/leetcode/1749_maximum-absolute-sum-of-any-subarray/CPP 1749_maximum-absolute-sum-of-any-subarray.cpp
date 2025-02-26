class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int currMax = 0;
        int currMin = 0;

        int maxest = 0;

        for (int &num : nums)
        {
            currMax = max(0, currMax) + num;
            currMin = min(0, currMin) + num;
            maxest = max({maxest, currMax, abs(currMin)});
        }

        return maxest;
    }
};