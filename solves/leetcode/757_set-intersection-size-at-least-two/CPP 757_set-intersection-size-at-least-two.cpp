class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
            if (a[1] == b[1]) 
                return a[0] > b[0];
            return a[1] < b[1]; });

        int cnt = 0;

        int eBefore = -1;
        int e = -1;

        for (auto &interval : intervals)
        {
            int sP = interval[0];
            int eP = interval[1];

            if (sP > eBefore)
            {
                cnt++;
                cnt += sP > e;
                eBefore = sP > e ? eP - 1 : e;
                e = eP;
            }
        }

        return cnt;
    }
};