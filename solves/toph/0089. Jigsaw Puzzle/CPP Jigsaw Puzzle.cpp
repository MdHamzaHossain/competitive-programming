#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, m, more;
    char c;
    cin >> h >> c >> m >> more;
    int timeToGo = 11 * 60 + 15;
    int desTime = h * 60 + m + more;
    cout << (desTime > timeToGo ? "NO" : "YES") << endl;
    return 0;
}