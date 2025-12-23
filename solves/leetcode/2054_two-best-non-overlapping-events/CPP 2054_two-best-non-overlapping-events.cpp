// TODO
class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {

        ranges::sort(events);
        const int n = events.size();
        vector<int> mxS(n + 1);
        for (int i = n - 1; i >= 0; --i)
            mxS[i] = max(mxS[i + 1], events[i][2]);

        int mx = 0;

        for (const auto &currentEvent : events)
        {
            int curr = currentEvent[2];

            int l = 0;
            int r = n - 1;
            int firstTrueIndex = -1;

            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (events[mid][0] > currentEvent[1])
                    firstTrueIndex = mid,
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            if (firstTrueIndex != -1)
                curr += mxS[firstTrueIndex];

            mx = max(mx, curr);
        }

        return mx;
    }
};