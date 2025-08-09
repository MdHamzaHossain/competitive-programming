class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        auto l = log2(n);
        return l >= 0 && ((long long)l == l);
    }
};