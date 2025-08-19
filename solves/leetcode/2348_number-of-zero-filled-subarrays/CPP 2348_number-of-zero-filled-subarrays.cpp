class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long res = 0;
        int weTheZeroes = 0;
        for (auto e : nums)
        {
            if (e == 0)
            {
                weTheZeroes++;
                res += weTheZeroes;
            }
            else
            {
                weTheZeroes = 0;
            }
        }

        return res;
    }
};