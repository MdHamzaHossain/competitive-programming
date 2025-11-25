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
ll rec(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll x = rec(a, b / 2);
    x = modMul(x, x);
    if (b % 2 == 1)
        x = modMul(x, a);
    return x;
}
ll dfs(map<ll, vector<ll>> &e, ll i, ll d, vector<ll> &v, bitset<1000000 + 3> &visited)
{
    if (visited[i])
        return 0;
    visited[i] = 1;
    ll s = 0;
    for (auto k : e[i])
    {
        s += dfs(e, k, d + 1, v, visited);
    }
    v.push_back(d - s);
    return s + 1;
}
int main()
{
    ll n, k;
    SCANLL(n);
    SCANLL(k);
    map<ll, vector<ll>> e;
    // cout << "DEBUG " << e.size() << endl;

    FORN(i, 0, n - 1)
    {
        ll x, y;
        SCANLL(x);
        SCANLL(y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    // cout << "DEBUG " << e.size() << endl;

    vector<ll> v;
    bitset<1000000 + 3> visited;
    dfs(e, 1, 0, v, visited);
    // cout << "DEBUG " << v.size() << endl;
    ll i = 0;
    ll res = 0;
    sort(b2e(v), greater<ll>());
    // while (i < k)
    // {
    // RFORN(j, v.size() - 1, i)
    // {
    // if (v[i] < v[j])
    // swap(v[j], v[i]);
    // }
    // cout << "DEBUG " << v[i] << endl;
    // res += v[i];
    // i++;
    // }
    FORN(i, 0, k)
    res += v[i];
    PRINTLL(res);
    return 0;
}