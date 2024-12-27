#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int x = 0;
    int y = 0;
    for (auto c : s1)
    {
        if (c >= '0' && c <= '9')
            x += (c - '0');
    }
    for (auto c : s2)
    {
        if (c >= '0' && c <= '9')
            y += (c - '0');
    }
    int a = x + y, b = x * y, c = abs(x - y);
    vector<int> arr = {x + y, x * y, abs(x - y)};
    sort(arr.begin(), arr.end());
    cout << "\"" << arr.at(1) << "\"" << endl;
}