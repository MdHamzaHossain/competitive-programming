#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    bool onlyBW = true;
    while (n--)
    {

        for (int c = 0; c < m; c++)
        {
            char ch;
            cin >> ch;
            if (ch != 'W' && ch != 'B' && ch != 'G')
                onlyBW = false;
        }
    }
    cout << (onlyBW ? "#Black&White" : "#Color") << endl;
}