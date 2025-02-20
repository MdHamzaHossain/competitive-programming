#include <bits/stdc++.h>
using namespace std;
#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define cinline(s) getline(cin, s)
#define ENDL "\n"
#define SCANINT(A) scanf("%d", &A)
#define SCANDOUBLE(A) scanf("%lf", &A)
#define SCANSTR(A) scanf("%s", A)
#define SCANLL(A) scanf("%lld", &A)
#define SCANLD(A) scanf("%Ld", &A)
#define PRINTINT(A) printf("%d", (A))
#define PRINTSTR(A) printf("%s", (A))
#define PRINTLL(A) printf("%lld", (A))
#define PRINTLD(A) printf("%Ld", (A))
#define PRINTEND printf("\n")
typedef long long ll;
typedef unsigned long long int ulli;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pairInt;
#define MP make_pair;
#define PB push_back;
#define b2e(a) a.begin(), a.end()
#define e2b(a) a.rbegin(), a.rend()
#define FORI(i, a, b) for (int i = a; i <= b; i++)
#define RFORI(i, a, b) for (int i = a; i >= b; i--)
#define FORN(i, a, b) for (int i = a; i < b; i++)
#define RFORN(i, a, b) for (int i = a; i > b; i--)
#define NTIMES(i, n) for (int i = 1; i <= n; i++)
#define testCase                        \
    ll testCaseAmount, currentTestCase; \
    SCANLL(testCaseAmount);             \
    for (currentTestCase = 1; currentTestCase <= testCaseAmount; currentTestCase++)
#define caseCout(i)           \
    PRINTSTR("Case ");        \
    PRINTLL(currentTestCase); \
    PRINTSTR(": ");           \
    if (1)                    \
        i;                    \
    PRINTEND;

int main()
{
    int n, m;
    SCANINT(n);
    SCANINT(m);
    int valid = 0;
    int tracker = 0;
    for (int p = n + 1; p <= m; p++)
    {
        tracker = 0;
        for (int i = 2; i <= (p / 2) + 1; i++)
        {
            if (p % i == 0)
            {
                tracker++;
            }
        }
        if (tracker == 0)
        {
            if (p == m)
            {
                PRINTSTR("YES");
                valid = 1;
                break;
            }
            else
            {
                PRINTSTR("NO");
                valid = 1;
                break;
            }
        }
    }
    if (!valid)
    {
        PRINTSTR("NO");
    }
    PRINTEND;
    return 0;
}