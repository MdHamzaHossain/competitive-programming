class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();
        int res = 0;
        int count = 0;

        for (int i = 0; i < n * 2; ++i)
        {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n])
                count = 1;
            else
                count++;

            if (i >= n && count >= k)
                res++;
        }

        return res;
    }
};