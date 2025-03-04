class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        int valid = 1;
        while (n > 0)
        {
            if (n % 3 > 1)
            {
                valid = 0;
                break;
            }
            n /= 3;
        }
        return valid;
    }
};