class Solution
{
public:
    int countPermutations(vector<int> &complexity)
    {
        const long long MOD = 1e9 + 7;
        const int lowest = complexity[0];
        for (int i = 1; i < complexity.size(); i++)
        {
            if (complexity[i] <= lowest)
            {
                return 0;
            }
        }
        long long fact = complexity.size() - 1;
        for (int i = fact - 1; i > 1; i--)
        {
            fact = fact * i % MOD;
        }
        return static_cast<int>(fact);
    }
};