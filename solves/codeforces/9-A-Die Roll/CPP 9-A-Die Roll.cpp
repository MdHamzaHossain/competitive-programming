
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y, w;
    cin >> y >> w;
    int winPos = max(y, w);
    string res;
    if (y == w && w == 12)
    {
        cout << "0/1" << endl;
        return 0;
    }
    switch (winPos)
    {
    case 1:
        res = "1/1";
        break;
    case 2:
        res = "5/6";
        break;
    case 3:
        res = "2/3";
        break;
    case 4:
        res = "1/2";
        break;
    case 5:
        res = "1/3";
        break;
    case 6:
        res = "1/6";
        break;
    }

    cout << res << endl;

    return 0;
}