// TODO
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int numIceCreams = costs.size();
        for (int i = 0; i < numIceCreams; ++i)
        {
            if (coins < costs[i])
            {
                return i;
            }
            coins -= costs[i];
        }
        return numIceCreams;
    }
};