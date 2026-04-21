// TODO
class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int n = colors.size();
        int maxDist = 0;
        for (int i = n - 1; i > 0; --i)
        {
            if (colors[0] != colors[i])
            {
                maxDist = max(maxDist, i);
                break;
            }
        }
        for (int i = 0; i < n - 1; ++i)
        {
            if (colors[n - 1] != colors[i])
            {
                maxDist = max(maxDist, n - 1 - i);
                break;
            }
        }

        return maxDist;
    }
};