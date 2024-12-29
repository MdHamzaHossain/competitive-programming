#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n2;
        cin >> n2;
        if (n2 == 2)
        {
            cout << 1 << endl;
            continue;
        }
        int am = (n2 / 4) + (n2 % 4) / 2;
        cout << am << endl;
    }
    return 0;
}