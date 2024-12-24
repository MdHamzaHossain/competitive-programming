#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int x = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "X++" || s == "++X")
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    cout << x;
}