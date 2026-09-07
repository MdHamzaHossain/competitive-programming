// TODO
class Solution
{
public:
    const int MOD = 1e9 + 7;

    int distinctSubseqII(string s)
    {

        vector<long> dp(26, 0);

        for (char &ch : s)
        {
            int charIndex = ch - 'a';

            dp[charIndex] = accumulate(dp.begin(), dp.end(), 1L) % MOD;
        }

        return accumulate(dp.begin(), dp.end(), 0L) % MOD;
    }
};
