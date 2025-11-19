class Solution
{
public:
    short findFinalValue(const vector<int> &nums, short original)
    {
        bitset<1000 + 1> t;
        for (const short &e : nums)
        {
            t[e] = 1;
        }
        for (short i = original; i < 2001; i *= 2)
        {
            original = i;
            if (i >= 1001 || !t[i])
                break;
        }
        return original;
    }
};