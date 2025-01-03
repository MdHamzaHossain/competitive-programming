#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> cal;
    int total = 0;
    for (int i = 1; i < 5; i++)
    {
        int te;
        cin >> te;
        cal['0' + i] = te;
    }
    string s;
    cin >> s;
    for (auto c : s)
    {
        total += cal[c];
    }
    cout << total << endl;
}