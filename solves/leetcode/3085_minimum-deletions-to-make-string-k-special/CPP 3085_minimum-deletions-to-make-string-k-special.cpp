class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        int minDel = 100010;
        vector<int> charMapper(26);

        for (const char c : word)
            charMapper[c - 'a']++;

        for (int e : charMapper)
        {
            int deletions = 0;
            for (const int freq : charMapper)
                if (freq < e)
                    deletions += freq;
                else
                    deletions += max(0, freq - (e + k));
            minDel = min(minDel, deletions);
        }

        return minDel;
    }
};