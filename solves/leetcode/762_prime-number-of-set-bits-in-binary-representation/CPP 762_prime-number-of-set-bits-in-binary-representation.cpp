
class Solution
{
public:
    int countPrimeSetBits(const int left, const int right)
    {
        int cnt = 0;
        for (unsigned int i = left; i <= right; i++)
        {
            cnt += 665772 >> __builtin_popcount(i) & 1;
        }
        return cnt;
    }
};