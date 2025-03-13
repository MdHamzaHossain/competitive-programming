class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int tracker[n + 1];
        int m = queries.size();
        int l = 0, r = m + 1;

        auto check = [&](int k) -> bool
        {
            memset(tracker, 0, sizeof(tracker));

            for (int i = 0; i < k; ++i)
            {

                tracker[queries[i][0]] += queries[i][2];
                tracker[queries[i][1] + 1] -= queries[i][2];
            }

            for (int i = 0, sum = 0; i < n; ++i)
            {
                sum += tracker[i];
                if (nums[i] > sum)
                {
                    return false;
                }
            }

            return true;
        };

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l > m ? -1 : l;
    }
};