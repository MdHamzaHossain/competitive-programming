class Solution
{
public:
    int maxScore(string s)
    {
        vector<int> zeroes;
        vector<int> ones = vector<int>(s.size(), 0);

        int weTheZeroes = s[0] == '0',
            weTheOnes = s[s.size() - 1] == '1';

        zeroes.push_back(0);
        zeroes.push_back(weTheZeroes);
        ones[s.size() - 1] = weTheOnes;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                weTheZeroes++;
            }
            if (s[s.size() - 1 - i] == '1')
            {
                weTheOnes++;
            }
            zeroes.push_back(weTheZeroes);

            ones[s.size() - 1 - i] = weTheOnes;
        }
        int maxScore = 0;
        for (int i = 1; i < s.size(); i++)
        {
            maxScore = max(maxScore, zeroes[i] + ones[i]);
        }
        return maxScore;
    }
};