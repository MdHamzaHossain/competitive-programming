class Solution
{
public:
    int smallestNumber(int n, int t)
    {
        int res = n;
        while (true)
        {
            int te = res;
            int prod = 1;
            while (te > 0)
            {
                prod *= (te % 10);
                te /= 10;
            }
            if (prod % t == 0)
                return res;
            res++;
        }
    }
};