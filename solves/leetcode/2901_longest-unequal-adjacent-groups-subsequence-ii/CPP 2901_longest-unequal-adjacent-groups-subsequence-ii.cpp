// TODO
class Solution
{
public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();

        auto canFormSequence = [](const string &left, const string &right)
        {
            if (left.size() != right.size())
            {
                return false;
            }
            int diffCount = 0;
            for (int i = 0; i < left.size(); ++i)
            {
                diffCount += left[i] != right[i];
            }
            return diffCount == 1;
        };

        vector<int> longestSubsequenceLength(n, 1);

        vector<int> previousIndex(n, -1);
        int maxLength = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {

                if (groups[i] != groups[j] && longestSubsequenceLength[i] < longestSubsequenceLength[j] + 1 && canFormSequence(words[i], words[j]))
                {

                    longestSubsequenceLength[i] = longestSubsequenceLength[j] + 1;
                    previousIndex[i] = j;

                    maxLength = max(maxLength, longestSubsequenceLength[i]);
                }
            }
        }
        vector<string> result;

        for (int i = 0; i < n; ++i)
            if (longestSubsequenceLength[i] == maxLength)
            {
                for (int j = i; j != -1; j = previousIndex[j])
                    result.push_back(words[j]);
                break;
            }
        reverse(result.begin(), result.end());
        return result;
    }
};
