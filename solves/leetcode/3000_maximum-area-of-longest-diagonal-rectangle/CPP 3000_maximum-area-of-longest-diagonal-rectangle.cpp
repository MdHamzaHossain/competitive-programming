class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int mx = 0;
        int mxSq = 0;
        for (auto e : dimensions)
        {
            int l = e[0];
            int w = e[1];
            int sq = l * l + w * w;

            if (mxSq < sq)
            {
                mxSq = sq;
                mx = l * w;
            }
            else if (mxSq == sq)
            {
                mx = max(mx, l * w);
            }
        }

        return mx;
    }
};