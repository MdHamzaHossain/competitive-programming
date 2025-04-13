int MOD = 1000000007;
class Solution
{
public:
    long modPow(long x, long n)
    {
        if (n == 0)
            return 1;
        if (n % 2 == 1)
            return x * modPow(x, n - 1) % MOD;
        return modPow(x * x % MOD, n / 2);
    }
    int countGoodNumbers(long long n)
    {
        return modPow(4 * 5, n / 2) * (n % 2 == 0 ? 1 : 5) % MOD;
    }
};
