class Solution
{
public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        unordered_map<string, int> prior = {
            {"electronics", 1},
            {"grocery", 2},
            {"pharmacy", 3},
            {"restaurant", 4}};
        const int n = code.size();
        vector<int> indice;
        for (int i = 0; i < n; i++)
        {
            bitset<1> t;
            t[0] = !code[i].empty();
            if (t[0])
                for (auto &e : code[i])
                    if (e != '_' && !isalnum(e))
                    {
                        t[0] = 0;
                        break;
                    };
            if (t[0] && isActive[i] && prior[businessLine[i]])
                indice.push_back(i);
        }
        sort(indice.begin(), indice.end(), [&code, &businessLine, &prior](int &a, int &b) -> bool
             {
            if(prior[businessLine[a]] == prior[businessLine[b]] ) return code[a] <code[b];
            else return prior[businessLine[a]] < prior[businessLine[b]]; });
        vector<string> res;
        for (auto e : indice)
            res.push_back(code[e]);
        return res;
    }
};