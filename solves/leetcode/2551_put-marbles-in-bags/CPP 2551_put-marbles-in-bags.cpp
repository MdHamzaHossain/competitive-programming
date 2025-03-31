#define ll long long
class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        vector<ll> v;
        ll mn = 0;
        ll mx = 0;

        for (ll i = 0; i + 1 < weights.size(); ++i)
            v.push_back(weights[i] + weights[i + 1]);

        ranges::sort(v);

        for (int i = 0; i < k - 1; ++i)
        {
            mn += v[i];
            mx += v[v.size() - 1 - i];
        }

        return mx - mn;
    }
};