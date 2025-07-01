class Solution
{
public:
    int possibleStringCount(string word)
    {
        int pos = 1;
        for (int i = 1; i < word.size(); i++)
            pos += (word[i] == word[i - 1]);
        return pos;
    }
};