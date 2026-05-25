// TODO
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();

        int prefixSum[n + 1];
        memset(prefixSum, 0, sizeof(prefixSum));
        prefixSum[1] = 1;

        bool canReachPosition[n];
        memset(canReachPosition, 0, sizeof(canReachPosition));
        canReachPosition[0] = true;

        for (int i = 1; i < n; ++i)
        {

            if (s[i] == '0')
            {

                int leftBound = max(0, i - maxJump);

                int rightBound = i - minJump;

                canReachPosition[i] = (leftBound <= rightBound) &&
                                      (prefixSum[rightBound + 1] - prefixSum[leftBound] > 0);
            }

            prefixSum[i + 1] = prefixSum[i] + canReachPosition[i];
        }

        return canReachPosition[n - 1];
    }
};
