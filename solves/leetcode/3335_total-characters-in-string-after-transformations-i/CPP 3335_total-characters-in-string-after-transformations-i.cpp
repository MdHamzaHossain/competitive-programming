class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        constexpr int kMod = 1'000'000'007;
        vector<int> freq(26);

        for (const char c : s)
            freq[c - 'a']++;

        while (t--)
        {
            vector<int> newFreq(26);
            for (int i = 0; i < 25; ++i)
                newFreq[i + 1] = freq[i];
            newFreq[0] = freq[25];
            newFreq[1] = (newFreq[1] + freq[25]) % kMod;
            freq = move(newFreq);
        }

        return accumulate(freq.begin(), freq.end(), 0L) % kMod;
    }
};