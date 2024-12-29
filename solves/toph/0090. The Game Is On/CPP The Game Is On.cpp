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
        string s;
        cin >> s;
        int kills = 0;
        bool hitZero = false;

        for (auto c : s)
        {
            if (c == '0')
            {
                hitZero = !hitZero;
            }
            else if (c == '1' && hitZero)
            {
                kills++;
                hitZero = !hitZero;
            }
        }
        cout << kills << endl;
    }
    return 0;
}
Download
