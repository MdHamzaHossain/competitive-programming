class Solution
{
public:
    bool isSubsequence(const string &subseq, const string &s, int k)
    {
        int i = 0;
        for (const char c : s)
            if (c == subseq[i])
                if (++i == subseq.length())
                {
                    if (--k == 0)
                        return true;
                    i = 0;
                }
        return false;
    }
    string longestSubsequenceRepeatedK(const string &s, int k)
    {
        string res;
        vector<int> charMapper(26);
        vector<char> possibleChars;
        queue<string> q{{""}};

        for (const char c : s)
            ++charMapper[c - 'a'];

        for (char c = 'a'; c <= 'z'; ++c)
            if (charMapper[c - 'a'] >= k)
                possibleChars.push_back(c);

        while (!q.empty())
        {
            const string currSubseq = q.front();
            q.pop();
            if (currSubseq.length() * k > s.length())
                return res;
            for (const char c : possibleChars)
            {
                const string &newSubseq = currSubseq + c;
                if (isSubsequence(newSubseq, s, k))
                {
                    q.push(newSubseq);
                    res = newSubseq;
                }
            }
        }

        return res;
    }
};