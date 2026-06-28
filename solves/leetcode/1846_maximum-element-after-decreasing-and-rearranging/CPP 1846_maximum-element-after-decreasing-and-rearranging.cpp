// TODO
class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {

        sort(arr.begin(), arr.end());

        arr[0] = 1;

        int maxElement = 1;

        for (int i = 1; i < arr.size(); ++i)
        {

            int decrementAmount = max(0, arr[i] - arr[i - 1] - 1);

            arr[i] -= decrementAmount;

            maxElement = max(maxElement, arr[i]);
        }

        return maxElement;
    }
};
