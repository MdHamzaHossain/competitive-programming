class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        int res = 0, totMeets = 0;
        for (auto &e : meetings)
        {
            int l = e[0], r = e[1];
            if (totMeets < l)
                res += l - totMeets - 1;
            totMeets = max(totMeets, r);
        }
        res += days - totMeets;
        return res;
    }
};