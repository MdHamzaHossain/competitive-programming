class Solution
{
public:
    vector<int> dp = vector<int>(50, -1);
    int rec(int n)
    {
        if (n <= 2)
            return n;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = rec(n - 1) + rec(n - 2);
        return dp[n];
    }
    int climbStairs(int n)
    {
        return rec(n);
    }
};