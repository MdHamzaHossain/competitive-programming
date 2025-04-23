class Solution
{
public:
    int countLargestGroup(int n)
    {
        int tracker[40] = {};

        int mx = 0;
        int mxSize = 0;

        for (int i = 1; i <= n; ++i)
        {
            int sum = 0;

            int x = i;
            while (x)
            {
                sum += x % 10;
                x = x / 10;
            }

            tracker[sum]++;

            if (mxSize < tracker[sum])
            {
                mxSize = tracker[sum];
                mx = 1;
            }
            else if (mxSize == tracker[sum])
                ++mx;
        }

        return mx;
    }
};