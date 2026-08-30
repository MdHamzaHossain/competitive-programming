// TODO
class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {

        int minIndex = 0, maxIndex = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] < nums[minIndex])
            {
                minIndex = i;
            }
            if (nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }

        if (minIndex > maxIndex)
        {
            swap(minIndex, maxIndex);
        }

        int deleteFromLeft = maxIndex + 1;
        int deleteFromRight = n - minIndex;
        int deleteFromBothEnds = (minIndex + 1) + (n - maxIndex);

        return min({deleteFromLeft, deleteFromRight, deleteFromBothEnds});
    }
};
