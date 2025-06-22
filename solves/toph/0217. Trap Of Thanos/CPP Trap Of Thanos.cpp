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
#define SCANCH(A) scanf("%c", &A)
#define SCANLL(A) scanf("%lld", &A)
#define SCANLD(A) scanf("%Lf", &A)
#define PRINTINT(A) printf("%d", (A))
#define PRINTDOUBLE(A) printf("%lf", (A))
#define PRINTSTR(A) printf("%s", (A))
#define PRINTCH(A) printf("%c", (A))
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

        vector<vector<ld>> v(4, vector<ld>(4, 0.0));
        int modulator = 0;
        FORN(i, 0, 6)
        {
            int t;
            SCANINT(t);
            v[i / 2][modulator] = (ld)t;
            modulator = !modulator;
        }
        ld exesInAGroup = v[0][0] + v[1][0] + v[2][0];
        ld whyInAGroup = v[0][1] + v[1][1] + v[2][1];

        getchar();
        char c;
        SCANCH(c);

        int val = c - 'A';
        ld res = sqrt(pow((v[val][0] - ((exesInAGroup - v[val][0]) / (ld)2.0)), 2) + pow((v[val][1] - (whyInAGroup - v[val][1]) / 2.0), 2));
        caseCout(printf("%.3Lf", res));
    }
    return 0;
}
