class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        string res = "";
        bool bracOn = false;
        unordered_map<string, string> mp;
        for (auto &e : knowledge)
        {
            mp[e[0]] = e[1];
        }
        string t = "";
        for (auto &e : s)
        {
            if (!bracOn)
            {
                if (e == '(')
                {
                    bracOn = 1;
                    continue;
                }
                res += e;
            }
            else
            {
                if (e == ')')
                {
                    if (mp.find(t) == mp.end())
                        t = "?";
                    else
                        t = mp[t];
                    res += t;
                    bracOn = 0;
                    t = "";
                }
                else
                {
                    t += e;
                }
            }
        }
        return res;
    }
};