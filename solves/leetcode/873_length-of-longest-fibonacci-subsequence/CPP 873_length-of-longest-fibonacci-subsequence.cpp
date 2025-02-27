class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        map<int, int> indexTracker;
        int n = arr.size();
        for (int i = 0; i < n; ++i)
        {
            indexTracker[arr[i]] = i;
        }

        vector<vector<int>> tracker(n, vector<int>(n, 2));
        int mx = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int prev = arr[i] - arr[j];
                if (indexTracker.count(prev))
                {
                    int k = indexTracker[prev];
                    if (k < j)
                    {
                        tracker[j][i] = max(tracker[j][i], tracker[k][j] + 1);
                        mx = max(mx, tracker[j][i]);
                    }
                }
            }
        }
        return mx > 2 ? mx : 0;
    }
};