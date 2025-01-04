class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<char> letts = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int count = 0;
        for (int i = 0; i < letts.size(); i++)
        {
            map<char, int> uniques;
            char c = letts[i];
            int first = s.find_first_of(c);
            int last = s.find_last_of(c);
            int uniqueCount = 0;
            for (int j = first + 1; j < last; j++)
            {
                if (uniques[s[j]])
                    continue;
                uniques[s[j]] = 1;
                uniqueCount++;
            }
            count += uniqueCount;
        }
        return count;
    }
};