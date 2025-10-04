// TODO
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int ticketDurations[3] = {1, 7, 30};
        int numDays = days.size();
        int dp[numDays];
        memset(dp, 0, sizeof(dp));
        function<int(int)> calculateMinCost = [&](int dayIndex)
        {
            if (dayIndex >= numDays)
                return 0;

            if (dp[dayIndex])
                return dp[dayIndex];
            dp[dayIndex] = INT_MAX;

            for (int ticketType = 0; ticketType < 3; ++ticketType)
            {
                int nextDayIndex = lower_bound(days.begin(), days.end(),
                                               days[dayIndex] + ticketDurations[ticketType]) -
                                   days.begin();

                dp[dayIndex] = min(dp[dayIndex],
                                   calculateMinCost(nextDayIndex) + costs[ticketType]);
            }
            return dp[dayIndex];
        };

        return calculateMinCost(0);
    }
};