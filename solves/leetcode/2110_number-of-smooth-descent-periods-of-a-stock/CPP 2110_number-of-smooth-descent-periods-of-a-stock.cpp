class Solution
{
public:
    long long getDescentPeriods(const vector<int> &prices)
    {
        long long ans = 0;
        int cons = 1;
        unsigned int prev = 0;
        const int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            const int c = prices[i];
            if (prev - 1 == c)
                cons++;
            else
                cons = 1;
            ans += cons;
            prev = c;
        }

        ;
        return ans;
    }
};