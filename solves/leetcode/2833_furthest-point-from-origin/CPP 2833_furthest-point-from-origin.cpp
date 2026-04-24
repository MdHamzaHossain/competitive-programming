class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int lS = 0;
        int rS = 0;
        int dS = 0;
        for (auto &e : moves)
        {
            if (e == 'L')
            {
                lS++;
            }
            else if (e == 'R')
                rS++;
            else
                dS++;
        }
        return max(lS, rS) + dS - min(lS, rS);
    }
};
