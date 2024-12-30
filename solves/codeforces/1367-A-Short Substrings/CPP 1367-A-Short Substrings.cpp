#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string res = "";
        for (int i = 0; i <= s.size(); i += 2)
        {
            // cout << i << " " << s[i] << endl;
            res += s[i == s.size() ? s.size() - 1 : i];
        }
        cout << res << endl;
    }
}