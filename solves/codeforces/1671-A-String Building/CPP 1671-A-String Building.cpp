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
typedef vector<ll> vll;
typedef pair<int, int> pairInt;
typedef pair<ll, ll> pairLL;
#define MP make_pair
#define PB push_back
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
#define MOD 1000000007
inline void normal(ll &a)
{
    if (abs(a) >= MOD)
        a %= MOD;
    (a < 0) && (a += MOD);
}
inline ll modMul(ll a, ll b)
{
    normal(a), normal(b);
    return (a * b) % MOD;
}
inline ll modAdd(ll a, ll b)
{
    normal(a), normal(b);
    return (a + b) % MOD;
}
inline ll modSub(ll a, ll b)
{
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
inline ll modPow(ll b, ll p)
{
    ll r = 1;
    b %= MOD;
    while (p)
    {
        if (p & 1)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1;
    }
    return r;
}
inline ll modInverse(ll a) { return modPow(a, MOD - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll findMinDivs(ll &n, ll &n2)
{
    if (n & 1)
        return 0;
    int cnt = 0;
    while (n && n % 8 == 0 && n / 8 >= n2)
    {
        n /= 8;
        cnt++;
    }
    while (n && n % 4 == 0 && n / 4 >= n2)
    {
        n /= 4;
        cnt++;
    }
    while (n && n % 2 == 0 && n / 2 >= n2)
    {
        n /= 2;
        cnt++;
    }
    return cnt;
}
int main()
{
    testCase
    {

        string s;
        cin >> s;
        const int n = s.size();
        int cnt = 0;
        bool pos = true;
        if (n == 1 || (n == 2 && s[0] != s[1]))
            pos = false;
        else
        {
            char prev = s[0];
            FORN(i, 1, n)
            {
                const char c = s[i];
                if (prev == c)
                    cnt++;
                else if (prev != c)
                {
                    if (cnt == 0)
                    {
                        pos = false;
                        break;
                    }
                    cnt = 0;
                }
                if (i == n - 1 && !cnt)
                    pos = false;
                prev = c;
            }
        }

        PRINTSTR(pos ? "YES" : "NO");
        PRINTEND;
    }
    return 0;
}
