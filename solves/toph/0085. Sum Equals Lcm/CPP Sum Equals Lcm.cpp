#define ll long long
#define ull unsigned long long
#define ulli unsigned long long int
#define b2e(a) a.begin(), a.end()
#define e2b(a) a.rbegin(), a.rend()
#define forI(i, a, b) for (int i = a; i <= b; i++)
#define rforI(i, a, b) for (int i = a; i >= b; i--)
#define forN(i, b) for (int i = 0; i < b; i++)
#define caseCout(i) cout << "Case " << i << ": "
#define nTimes(i, n) for (int i = 1; i <= n; i++)
#define rforN(i, a, b) for (int i = a; i > b; i--)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tC;
    cin >> tC;
    while (tC--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1;
        }
        else if (n == 2)
            cout << -1;
        else if (n % 2 == 0)
        {
            cout << n + 1 << " 2 2 ";
            nTimes(weTheOnes, n - 3)
            {
                cout << 1;
                if (weTheOnes != (n - 3))
                    cout << " ";
            }
        }
        else
        {
            cout << n << " 2 ";
            nTimes(weTheOnes, n - 2)
            {
                cout << 1;
                if (weTheOnes != (n - 2))
                    cout << " ";
            }
        }
        cout << endl;
    }
}