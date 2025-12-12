class Solution
{
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {
        vector<int> cnt(numberOfUsers);
        bitset<101> oS;
        oS.set();
        int n = events.size();
        for (int i = 0; i < n; i++)
        {
            vector<string> e = events[i];
            if (e[0][0] == 'O')
            {
                // e is of type vector<string>
                vector<string> t(3);
                t[0] = "A";
                t[1] = to_string((stoi(e[1]) + 60));
                t[2] = e[2];
                events.push_back(t);
            }
        }
        map<char, int> priorities;
        priorities['A'] = 0;
        priorities['O'] = 1;
        priorities['M'] = 2;
        sort(events.begin(), events.end(), [&priorities](vector<string> &a, vector<string> &b) -> bool

             {
                 if(stoi(a[1]) == stoi(b[1])) return priorities[a[0][0]] < priorities[b[0][0]]; 
                 else return stoi(a[1]) < stoi(b[1]); });

        for (auto e : events)
        {

            if (e[0][0] == 'O')
            {
                string s = e[2];
                string num = "";
                for (auto c : s)
                {
                    if (c == ' ')
                    {
                        oS[stoi(num)] = 0;
                        num = "";
                    }
                    else
                        num += c;
                }

                oS[stoi(num)] = 0;
            }
            else if (e[0][0] == 'A')
            {
                string s = e[2];
                string num = "";
                for (auto c : s)
                {
                    if (c == ' ')
                    {
                        oS[stoi(num)] = 1;
                        num = "";
                    }
                    else
                        num += c;
                }

                oS[stoi(num)] = 1;
            }
            else
            {
                if (e[2][0] == 'A')
                {
                    for (auto &e : cnt)
                    {
                        e++;
                    }
                }
                else if (e[2][0] == 'H')
                {
                    for (int j = oS._Find_first(); j < numberOfUsers; j = oS._Find_next(j))
                    {
                        cnt[j]++;
                    }
                }
                else
                {
                    string s = e[2];
                    string num = "";
                    for (auto c : s)
                    {
                        if (c == ' ')
                        {
                            cnt[stoi(num)]++;
                            num = "";
                        }
                        else if (c == 'i' || c == 'd')
                        {
                        }
                        else
                            num += c;
                    }

                    cnt[stoi(num)]++;
                }
            }
        }
        // for (auto &e : events)
        //    cout << e[0] << " " << e[1] << " " << e[2] << endl;
        return cnt;
    }
};