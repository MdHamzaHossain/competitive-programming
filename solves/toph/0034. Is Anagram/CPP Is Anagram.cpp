#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a;
    cin >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << (a == b ? "Yes" : "No") << endl;
    return 0;
}