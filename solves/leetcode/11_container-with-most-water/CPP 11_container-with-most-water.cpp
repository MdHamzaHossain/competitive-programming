#define ll long long
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxArea = 0;
        int l = 0, r = height.size() - 1;
        while (l < r)
        {
            const int L = height[l];
            const int R = height[r];
            maxArea = max(maxArea, (r - l) * min(L, R));
            if (L < R)
                l++;
            else
                r--;
        }
        return maxArea;
    }
};