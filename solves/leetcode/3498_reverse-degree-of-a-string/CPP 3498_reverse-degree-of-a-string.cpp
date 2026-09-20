class Solution
{
public:
    int reverseDegree(string s)
    {
        int sum = 0;
        map<char, int> mp;
        const string t = "-zyxwvutsrqponmlkjihgfedcba";
        for (int i = 1; i < 27; i++)
            mp[t[i]] = i;
        for (int i = 0; i < s.size(); i++)
        {
            sum += mp[s[i]] * (i + 1);
        }
        return sum;
    }
};