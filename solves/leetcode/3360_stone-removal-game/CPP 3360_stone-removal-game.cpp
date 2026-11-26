class Solution
{
public:
    bool canAliceWin(int n)
    {
        bool al = 0;
        if (n < 10)
            return 0;
        n -= 10;
        int neg = 9;
        while (neg > 0)
        {
            n -= neg;
            if (n < 0)
            {
                if (al == 1)
                    return 0;
                else
                    return 1;
            }
            if (n == 0)
            {
                if (al == 1)
                    return 1;
                else
                    return 0;
            }
            neg--;
            al = !al;
        }
        return 0;
    }
};