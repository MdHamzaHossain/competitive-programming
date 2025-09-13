// * FIRST SOL
class Solution
{
public:
    int maxFreqSum(string s)
    {
        map<char, int> charMapper;
        string vowels = "aeiou";
        int mostVow = 0;
        char vowMos;
        int mostCons = 0;
        char consMos;
        for (auto c : s)
        {
            charMapper[c]++;
            if (vowels.find(c) != string::npos)
            {
                if (charMapper[c] > mostVow)
                {
                    mostVow = charMapper[c];
                    vowMos = c;
                }
            }
            else
            {
                if (charMapper[c] > mostCons)
                {
                    mostCons = charMapper[c];
                    consMos = c;
                }
            }
        }
        return mostCons + mostVow;
    }
};
// * Second Sol
class Solution
{
public:
    int maxFreqSum(string s)
    {
        vector<int> v(27, 0);
        string vowels = "aeiou";
        int mostVow = 0;
        int mostCons = 0;
        for (auto c : s)
        {
            v[c - 'a']++;
            int cnt = v[c - 'a'];
            if (vowels.find(c) != string::npos)
            {
                if (cnt > mostVow)
                    mostVow = cnt;
            }
            else if (cnt > mostCons)
                mostCons = cnt;
        }
        return mostCons + mostVow;
    }
};
//* THIRD SOL
class Solution
{
public:
    int maxFreqSum(const string &s)
    {
        signed char v[28];
        for (signed char i = 0; i < s.size(); i++)
        {
            const signed char c = s[i];
            const signed char j = c - 'a';
            v[j]++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                if (v[j] > v[26])
                    v[26] = v[j];
            }
            else if (v[j] > v[27])
                v[27] = v[j];
        }
        return v[27] + v[26];
    }
};