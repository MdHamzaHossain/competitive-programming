class Solution
{
public:
    int sLength;
    vector<int> tracker, resSeq;
    bool dfs(int pos)
    {
        if (pos == sLength * 2)
            return true;

        if (resSeq[pos])
            return dfs(pos + 1);

        for (int i = sLength; i > 1; --i)
        {
            if (tracker[i] && pos + i < sLength * 2 && !resSeq[pos + i])
            {
                resSeq[pos] = resSeq[pos + i] = i;
                tracker[i] = 0;

                if (dfs(pos + 1))
                    return true;
                tracker[i] = 2;
                resSeq[pos] = resSeq[pos + i] = 0;
            }
        }

        if (tracker[1])
        {
            resSeq[pos] = 1;
            tracker[1] = 0;

            if (dfs(pos + 1))
                return true;
            tracker[1] = 1;
            resSeq[pos] = 0;
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n)
    {
        sLength = n;
        tracker.resize(n * 2, 2);
        resSeq.resize(n * 2);
        tracker[1] = 1;

        dfs(1);
        vector<int> ans;
        for (int i = 1; i < n * 2; ++i)
        {
            ans.push_back(resSeq[i]);
        }
        return ans;
    }
};