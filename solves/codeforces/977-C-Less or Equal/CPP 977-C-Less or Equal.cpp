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
    int n, k;
    SCANINT(n);
    SCANINT(k);
    vi vt;

    // SCANINT(mn);
    // vt.push_back(mn);

    FORN(i, 0, n)
    {

        int t;
        SCANINT(t);
        vt.push_back(t);
    }

    sort(b2e(vt));
    if (k == 0)
    {
        if (vt[0] == 1)
            PRINTINT(-1);
        else if (vt[0] > 1)
            PRINTINT(1);
        PRINTEND;
        return 0;
    }
    if (k <= n - 1)
    {
        if (vt[k - 1] == vt[k])
        {
            PRINTINT(-1);
            PRINTEND;
            return 0;
        }
        PRINTINT(vt[k - 1]);
        PRINTEND;
        return 0;
    }
    if (k == n)
        PRINTINT(vt[k - 1]);
}