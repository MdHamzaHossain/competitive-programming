// TODO
class Solution
{
public:
    int countTrapezoids(const vector<vector<int>> &points)
    {
        const int mod = 1e9 + 7;
        unordered_map<int, int> track;
        for (auto &e : points)
        {
            track[e[1]]++;
        }
        long long amount = 0, s = 0;
        for (auto &[k, v] : track)
        {
            long long t = 1LL * v * (v - 1) / 2;
            amount = (amount + s * t) % mod;
            s += t;
        }
        return (int)amount;
    }
};