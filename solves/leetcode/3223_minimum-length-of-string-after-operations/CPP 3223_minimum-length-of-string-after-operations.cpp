class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> charCount = vector<int>(26, 0);
        long long length = 0;
        for (char ch : s)
        {
            // charCount[ch-'a']++;
            length++;
            if (++charCount[ch - 'a'] == 3)
            {
                charCount[ch - 'a'] -= 2;
                length -= 2;
            }
        }
        return length;
    }
};