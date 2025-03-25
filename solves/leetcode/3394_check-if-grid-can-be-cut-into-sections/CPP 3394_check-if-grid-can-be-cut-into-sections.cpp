class Solution
{
public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<pair<int, int>> xTrack;
        vector<pair<int, int>> yTrack;

        for (const vector<int> rectangles : rectangles)
        {
            xTrack.emplace_back(rectangles[0], rectangles[2]);
            yTrack.emplace_back(rectangles[1], rectangles[3]);
        }
        ranges::sort(xTrack);
        ranges::sort(yTrack);
        int mx = -1;
        int cnt = 0;
        int prev = 0;

        for (const auto &[l, eend] : xTrack)
            if (l < prev)
            {
                prev = max(prev, eend);
            }
            else
            {
                prev = eend;
                ++cnt;
            }
        mx = cnt;
        cnt = 0;
        prev = 0;
        for (const auto &[l, eend] : yTrack)
            if (l < prev)
            {
                prev = max(prev, eend);
            }
            else
            {
                prev = eend;
                ++cnt;
            }
        mx = max(cnt, mx);
        return mx >= 3;
    }
};