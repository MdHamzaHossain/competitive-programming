// TODO
class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int maxEvents)
    {

        sort(events.begin(), events.end(), [](const auto &event1, const auto &event2)
             { return event1[1] < event2[1]; });

        int numEvents = events.size();
        int dp[numEvents + 1][maxEvents + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= numEvents; ++i)
        {

            int startTime = events[i - 1][0];
            int value = events[i - 1][2];

            vector<int> currentTime = {startTime};

            int lastEventIndex = lower_bound(events.begin(), events.begin() + i - 1, currentTime, [](const auto &a, const auto &b)
                                             { return a[1] < b[0]; }) -
                                 events.begin();

            for (int j = 1; j <= maxEvents; ++j)
                dp[i][j] = max(dp[i - 1][j], dp[lastEventIndex][j - 1] + value);
        }

        return dp[numEvents][maxEvents];
    }
};
