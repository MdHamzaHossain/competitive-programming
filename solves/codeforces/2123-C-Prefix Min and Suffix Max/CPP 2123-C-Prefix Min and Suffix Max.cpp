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
        ll n;
        SCANLL(n);
        vector<ll> v;
        FORN(i, 0, n)
        {
            ll t;
            SCANLL(t);
            v.push_back(t);
        }
        if (n == 1)
        {
            PRINTINT(1);
            PRINTEND;
            continue;
        }
        vector<ll> suffixMax(n + 2);
        vector<ll> prefixMin(n + 2);

        suffixMax[n - 1] = v[n - 1];
        // cout << "SUFFIX " << ENDL;
        RFORN(i, n - 2, -1)
        {
            // cout << "\n\tDEBUG " << i << " " << suffixMax[i + 1] << " " << v[i] << ENDL;

            suffixMax[i] = max(suffixMax[i + 1], v[i]);
        }
        // cout << "Prefix " << ENDL;
        prefixMin[0] = v[0];
        // FORN(i, 0, n)
        FORN(i, 1, n)
        {
            //  cout << "\n\tDEBUG " << i << " " << prefixMin[i - 1] << " " << v[i] << ENDL;
            prefixMin[i] = min(prefixMin[i - 1], v[i]);
        }
        FORN(i, 0, n)
        {
            if (i == 0 || i == n - 1)
            {
                PRINTCH('1');
                continue;
            }
            //  cout << "\nDEBUG2 " << i << " pm " << (i == 0 ? -1 : prefixMin[i - 1]) << " sm " << (i == n - 1 ? -1 : suffixMax[i + 1]) << ENDL;
            bool pC = (v[i] < prefixMin[i - 1]);
            bool sC = (v[i] > suffixMax[i + 1]);
            PRINTCH((pC || sC) ? '1' : '0');
        }
        PRINTEND;
    }
    return 0;
}
