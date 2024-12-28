#include <bits/stdc++.h>
using namespace std;
int main()
{
    int res;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int t;
            cin >> t;
            if (t == 1)
            {
                res = abs(2 - i) + abs(2 - j);
            }
        }
    }
    cout << res << endl;
    return 0;
}