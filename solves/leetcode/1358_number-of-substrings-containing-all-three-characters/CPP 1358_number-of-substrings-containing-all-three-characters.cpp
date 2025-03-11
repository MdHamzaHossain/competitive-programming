class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int tracker[3] = {-1, -1, -1};
        int subs = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            tracker[s[i] - 'a'] = i;
            int mn = min(tracker[0], min(tracker[1], tracker[2])) + 1;
            subs += mn;
        }

        return subs;
    }
};