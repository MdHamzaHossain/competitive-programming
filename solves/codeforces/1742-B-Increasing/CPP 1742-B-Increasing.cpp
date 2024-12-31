
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ulli unsigned long long int
#define b2e(a) a.begin(), a.end()
#define e2b(a) a.rbegin(), a.rend()
#define forI(i, a, b) for (int i = a; i <= b; i++)
#define rforI(i, a, b) for (int i = a; i >= b; i--)
#define forN(i, a, b) for (int i = a; i < b; i++)
#define rforN(i, a, b) for (int i = a; i > b; i--)
#define nTimes(i, n) for (int i = 1; i <= n; i++)
#define testCase                         \
    int testCaseAmount, currentTestCase; \
    cin >> testCaseAmount;               \
    for (currentTestCase = 1; currentTestCase <= testCaseAmount; currentTestCase++)
#define caseCout(i) cout << "Case " << currentTestCase << ": " << i << endl;

int main()
{
    int tes;
    cin >> tes;
    while (tes--)
    {
        int n;
        map<long long, long long> count;
        scanf("%d", &n);
        int valid = 1;
        while (n--)
        {
            long long t;
            scanf("%lld", &t);
            if (!count[t])
                count[t] = 1;
            else
            {
                valid = 0;
            }
        }
        // cout << (valid ? "YES" : "NO") << endl;
        printf("%s\n", valid ? "YES" : "NO");
    }
}