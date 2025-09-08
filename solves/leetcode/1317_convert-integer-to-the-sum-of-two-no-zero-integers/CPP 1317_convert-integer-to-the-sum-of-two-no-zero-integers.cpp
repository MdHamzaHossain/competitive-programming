// TODO
class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = 1; i < n; i++)
        {
            int t = n - i;
            if (to_string(i).find('0') == string::npos &&
                to_string(t).find('0') == string::npos)
                return {i, t};
        }

        return vector<int>(0);
    }
};