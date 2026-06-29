class Solution
{
public:
    int numOfStrings(const vector<string> &patterns, const string word)
    {
        int res = 0;
        for (const auto &s : patterns)
        {
            res += word.find(s) != string::npos;
        }
        return res;
    }
};