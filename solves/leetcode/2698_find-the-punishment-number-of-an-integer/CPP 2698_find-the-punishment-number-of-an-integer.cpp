class Solution
{
public:
    bool doTheSplits(int acc, int curr, const string &chars, int s,
                     int target)
    {
        if (s == chars.length())
            return target == acc + curr;
        const int d = chars[s] - '0';
        return doTheSplits(acc, curr * 10 + d, chars, s + 1, target) ||
               doTheSplits(acc + curr, d, chars, s + 1, target);
    }
    int punishmentNumber(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (doTheSplits(0, 0, to_string(i * i), 0, i))
                res += i * i;
        return res;
    }
};
