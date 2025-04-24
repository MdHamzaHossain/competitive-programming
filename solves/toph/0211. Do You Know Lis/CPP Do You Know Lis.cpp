#include <bits/stdc++.h>
using namespace std;
#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define cinline(s) getline(cin, s)
#define ENDL "\n"
#define SCANINT(A) scanf("%d", &A)
#define SCANDOUBLE(A) scanf("%lf", &A)
#define SCANSTR(A) scanf("%s", A)
#define SCANCH(A) scanf("%c", A)
#define SCANLL(A) scanf("%lld", &A)
#define SCANLD(A) scanf("%Lf", &A)
#define PRINTINT(A) printf("%d", (A))
#define PRINTSTR(A) printf("%s", (A))
#define PRINTLL(A) printf("%lld", (A))
#define PRINTLD(A) printf("%Lf", (A))
#define PRINTEND printf("\n")
typedef long long ll;
typedef unsigned long long int ulli;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pairInt;
#define MP make_pair;
#define PB push_back;
#define b2e(a) a.begin(), \
               a.end()
#define e2b(a) a.rbegin(), a.rend()
#define FORI(i, a, b) for (ll i = a; i <= b; i++)
#define RFORI(i, a, b) for (ll i = a; i >= b; i--)
#define FORN(i, a, b) for (ll i = a; i < b; i++)
#define RFORN(i, a, b) for (ll i = a; i > b; i--)
#define NTIMES(i, n) for (ll i = 1; i <= n; i++)
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
#define MATHPI acos(-1)

int main()
{
    testCase
    {
        int n, x;
        SCANINT(n);
        SCANINT(x);

        vi v1, v2;
        FORN(i, 0, n)
        {
            int t;
            SCANINT(t);
            (i < x ? v1 : v2).push_back(t);
        }
        sort(b2e(v1));
        sort(b2e(v2));
        ll ans = max(x, n - x);
        FORN(i, 0, x)
        {
            ll t = lower_bound(b2e(v2), v1[i]) - v2.begin();
            ans = max(ans, i + 1 + ((ll)v2.size() - (t)));
        }
        PRINTLL(ans);
        PRINTEND;
    }
}