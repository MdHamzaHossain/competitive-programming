// TODO
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {

        for (int &value : arr)
        {
            int bitCount = __builtin_popcount(value);
            value += bitCount * 100000;
        }

        sort(arr.begin(), arr.end());

        for (int &value : arr)
        {
            value %= 100000;
        }

        return arr;
    }
};