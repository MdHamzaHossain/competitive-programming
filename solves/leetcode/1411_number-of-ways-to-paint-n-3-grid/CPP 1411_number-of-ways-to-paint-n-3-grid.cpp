// TODO
const long long LEETMOD = (1e9 + 7);
class Solution
{
public:
    int numOfWays(int n)
    {
        long long c1 = 6;
        long long c3 = 6;

        for (int i = 1; i < n; ++i)
        {
            long long t2 = c1 * 3 + c3 * 2;
            long long t3 = c1 * 2 + c3 * 2;
            c1 = t2 % LEETMOD;
            c3 = t3 % LEETMOD;
        }

        return (c1 + c3) % LEETMOD;
    }
};
