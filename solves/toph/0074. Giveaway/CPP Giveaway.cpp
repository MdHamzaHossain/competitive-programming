#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bool subFound = false;
    for (auto c : s1)
    {
        int pos = s2.find(c);
        if (pos > -1)
        {
            subFound = true;
            break;
        }
    }
    cout << (subFound ? "YES" : "NO") << endl;
}