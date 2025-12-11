class Solution
{
public:
    int countCoveredBuildings(const int n, const vector<vector<int>> &buildings)
    {
        // The min and max Y on X
        vector<pair<int, int>> xS(n + 1, {1e5 + 2, 0});
        // The min and max X on Y
        vector<pair<int, int>> yS(n + 1, {1e5 + 2, 0});
        for (auto &e : buildings)
        {
            const int x = e[0];
            const int y = e[1];

            xS[x].first = min(xS[x].first, y);
            xS[x].second = max(xS[x].second, y);

            yS[y].first = min(yS[y].first, x);
            yS[y].second = max(yS[y].second, x);
        }
        int cnt = 0;
        for (auto &e : buildings)
        {
            const int x = e[0];
            const int y = e[1];
            if (xS[x].first < y && xS[x].second > y && yS[y].first < x && yS[y].second > x)
                cnt++;
        }
        return cnt;
    }
};