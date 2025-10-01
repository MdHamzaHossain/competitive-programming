class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int init = numBottles;
        int ans = numBottles;
        int rem = 0;
        while (init)
        {
            init += rem;
            rem = init % numExchange;
            init /= numExchange;
            ans += init;
        }
        return ans;
    }
};