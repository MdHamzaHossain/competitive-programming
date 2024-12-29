#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char t;
        cin >> t;
        int a = t - '0';
        cin >> t;
        int b = t - '0';
        cout << a + b << endl;
    }
    return 0;
}