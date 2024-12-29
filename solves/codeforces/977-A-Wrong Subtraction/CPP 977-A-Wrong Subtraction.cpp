#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int y = 0;
    while (b--)
    {

        if (a % 10 == 0)
        {
            a /= 10;
        }
        else
            a--;
    }
    cout << a << endl;
}
