#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, h, a, b;
    cin >> l >> h;
    a = l / h;
    b = l % h;
    cout << a << " " << b << " " << h;
    return 0;
}