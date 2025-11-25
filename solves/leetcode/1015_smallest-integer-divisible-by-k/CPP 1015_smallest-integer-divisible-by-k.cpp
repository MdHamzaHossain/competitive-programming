class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0)
            return -1;
        int rem = k;
        int t = 1;
        while (t <= k)
        {

            if (rem == 0)
                return t;

            rem = (rem * 10 + 1) % k;
            t++;
        }

        return -1;
    }
};
