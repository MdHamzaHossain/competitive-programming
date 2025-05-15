class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> res;
        for (int index = 0; index < words.size(); ++index)
            if (index == 0 || groups[index] != groups[index - 1])
                res.emplace_back(words[index]);
        return res;
    }
};