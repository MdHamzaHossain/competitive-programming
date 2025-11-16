class Solution
{
public:
    int numSub(const string &s)
    {
        unsigned int res = 0;
        unsigned int curr = 0;
        for (const char &e : s)
        {
            if (e == '1')
            {
                curr++;
                ;
                res = (res + curr) % (1000000000 + 7);
            }
            else
                curr = 0;
        }
        return res;
    }
};