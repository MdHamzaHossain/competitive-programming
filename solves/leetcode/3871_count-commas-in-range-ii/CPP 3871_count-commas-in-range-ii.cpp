class Solution
{
public:
    long long countCommas(long long n)
    {
        long long res = 0;
        long long t = 1e3;
        long long mul = 0;
        while (mul < 5)
        {
            if (n >= t)
            {
                res += (++mul) * (min(n, (long long)t * 1000LL - 1LL) - t + 1), t *= 1e3;
                cout << "Deb " << res << endl;
            }
            else
                break;
        }

        return res;
    }
};