class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> charCount(26);
        int oddM = 0;
        int evenM = s.length();

        for (char c : s)
            charCount[c - 'a']++;

        for (int e : charCount)
        {
            if (e == 0)
                continue;
            if (e % 2 == 0)
                evenM = min(evenM, e);
            else
                oddM = max(oddM, e);
        }

        return oddM - evenM;
    }
};