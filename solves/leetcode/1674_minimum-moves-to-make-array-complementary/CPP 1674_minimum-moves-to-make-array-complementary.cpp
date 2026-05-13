// TODO
class Solution
{
public:
    int minMoves(vector<int> &nums, int limit)
    {
        int n = nums.size();

        int costDifference[limit * 2 + 2];
        memset(costDifference, 0, sizeof(costDifference));

        for (int i = 0; i < n / 2; ++i)
        {
            int minVal = nums[i];
            int maxVal = nums[n - i - 1];

            if (minVal > maxVal)
            {
                swap(minVal, maxVal);
            }

            costDifference[2] += 2;
            costDifference[minVal + 1] -= 2;

            costDifference[minVal + 1] += 1;
            costDifference[minVal + maxVal] -= 1;

            costDifference[minVal + maxVal + 1] += 1;
            costDifference[maxVal + limit + 1] -= 1;

            costDifference[maxVal + limit + 1] += 2;
        }

        int minTotalMoves = n;
        int currentCost = 0;

        for (int targetSum = 2; targetSum <= limit * 2; ++targetSum)
        {
            currentCost += costDifference[targetSum];
            minTotalMoves = min(minTotalMoves, currentCost);
        }

        return minTotalMoves;
    }
};