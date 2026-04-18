class Solution
{
public:
    int mirrorDistance(int n)
    {
        const string s = to_string(n);
        const string sR = string(s.rbegin(), s.rend());
        long long res = abs(stoll(s) - stoll(sR));
        return res;
    }
};