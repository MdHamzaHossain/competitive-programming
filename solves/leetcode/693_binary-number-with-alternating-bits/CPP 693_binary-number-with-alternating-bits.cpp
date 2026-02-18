class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int prev = -1;
        bool flag = true;
        while (n)
        {
            int curr = n & 1;
            if (prev == curr)
            {
                flag = false;
                break;
            }
            prev = curr;
            n >>= 1;
        }
        return flag;
    }
};