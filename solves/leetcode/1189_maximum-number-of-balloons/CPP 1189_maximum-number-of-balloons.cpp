class Solution
{
public:
    int maxNumberOfBalloons(const &string text)
    {
        unordered_map<char, int> mp;
        for (auto &e : text)
            mp[e]++;
        mp['l'] /= 2;
        mp['o'] /= 2;
        int res = 0;
        const string bal = "balon";
        for (auto &e : bal)
        {
            res = min(mp[e]);
        }
        return res;
    }
};