class Solution
{
public:
    int maxDis(char a, char b, string s, int k)
    {
        int ans = 0, mx = 0, cnt = 0;
        for (char c : s)
        {
            if (c == a || c == b)
                ++mx;
            else if (cnt < k)
            {
                ++mx;
                ++cnt;
            }
            else
                --mx;
            ans = max(ans, mx);
        }
        return ans;
    };
    int maxDistance(string s, int k)
    {
        int a = maxDis('S', 'E', s, k);
        int b = maxDis('S', 'W', s, k);
        int c = maxDis('N', 'E', s, k);
        int d = maxDis('N', 'W', s, k);
        //* GOOD USAGE OF MAX
        return max({a, b, c, d});
    }
};