// TODO
class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {

        restrictions.push_back({1, 0});

        ranges::sort(restrictions);

        if (restrictions.back()[0] != n)
        {
            restrictions.push_back({n, n - 1});
        }

        int restrictionCount = restrictions.size();

        for (int i = 1; i < restrictionCount; ++i)
        {
            int currentPos = restrictions[i][0];
            int prevPos = restrictions[i - 1][0];
            int distance = currentPos - prevPos;
            int maxHeightFromPrev = restrictions[i - 1][1] + distance;

            restrictions[i][1] = min(restrictions[i][1], maxHeightFromPrev);
        }

        for (int i = restrictionCount - 2; i > 0; --i)
        {
            int currentPos = restrictions[i][0];
            int nextPos = restrictions[i + 1][0];
            int distance = nextPos - currentPos;
            int maxHeightFromNext = restrictions[i + 1][1] + distance;

            restrictions[i][1] = min(restrictions[i][1], maxHeightFromNext);
        }

        int maxHeight = 0;
        for (int i = 0; i < restrictionCount - 1; ++i)
        {
            int leftPos = restrictions[i][0];
            int rightPos = restrictions[i + 1][0];
            int leftHeight = restrictions[i][1];
            int rightHeight = restrictions[i + 1][1];
            int distance = rightPos - leftPos;
            int peakHeight = (leftHeight + rightHeight + distance) / 2;
            maxHeight = max(maxHeight, peakHeight);
        }

        return maxHeight;
    }
};
