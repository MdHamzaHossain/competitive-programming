// TODO
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {

        sort(arr2.begin(), arr2.end());

        int count = 0;

        for (int num : arr1)
        {

            auto iterator = lower_bound(arr2.begin(), arr2.end(), num - d);

            if (iterator == arr2.end() || *iterator > num + d)
            {
                count++;
            }
        }

        return count;
    }
};
