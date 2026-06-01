class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int p = 0;
        sort(cost.begin(), cost.end(), greater<int>());
        for (int i = 0; i < cost.size(); i++)
        {
            if ((i + 1) % 3 == 0)
            {
            }
            else
            {
                p += cost[i];
            }
        }
        return p;
    }
};