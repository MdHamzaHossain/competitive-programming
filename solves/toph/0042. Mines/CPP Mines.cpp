#define ll long long
#define ull unsigned long long
#define ulli unsigned long long int
#define b2e(a) a.begin(), a.end()
#define e2b(a) a.rbegin(), a.rend()
#define forI(i, a, b) for (int i = a; i <= b; i++)
#define rforI(i, a, b) for (int i = a; i >= b; i--)
#define forN(i, b) for (int i = 0; i < b; i++)
#define rforN(i, a, b) for (int i = a; i > b; i--)
#define nTimes(i, n) for (int i = 1; i <= n; i++)
#define testCase                         \
    int testCaseAmount, currentTestCase; \
    cin >> testCaseAmount;               \
    for (currentTestCase = 1; currentTestCase <= testCaseAmount; currentTestCase++)
#define caseCout(i) cout << "Case " << currentTestCase << ": " << i << endl;
#include <bits/stdc++.h>
using namespace std;

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

const double PI = acos(-1.0);
const ll mod = 1e9 + 7;

int compareQ(const void *a, const void *b)
{
    int *x = (int *)a, *y = (int *)b;
    return (*x) - (*y); // ascending
}
bool compD(int a, int b)
{
    return a >= b; // descending
}
#define mx 7368789
vector<bool> prime(mx, true);
int primeNums[mx];

void sieve(int n)
{

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int primeIndex = 0;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primeNums[primeIndex++] = p;
}
ulli modulo = 1000000007;
int main()
{

    int r, c;
    cin >> r >> c;
    string rows[r];
    forN(i, r) cin >> rows[i];
    forN(i, r)
    {
        forN(j, c)
        {
            int bombastic = 0;
            if (rows[i][j] == '.')
            {
                if ((j - 1 > -1) && rows[i][j - 1] == '*')
                    bombastic++;
                if (j + 1 < c && rows[i][j + 1] == '*')
                    bombastic++;
                if ((i - 1) > -1)
                {
                    if (rows[i - 1][j] == '*')
                        bombastic++;
                    if ((j - 1 > -1) && rows[i - 1][j - 1] == '*')
                        bombastic++;
                    if (j + 1 < c && rows[i - 1][j + 1] == '*')
                        bombastic++;
                }
                if ((i + 1) < r)
                {
                    if (rows[i + 1][j] == '*')
                        bombastic++;
                    if ((j - 1 > -1) && rows[i + 1][j - 1] == '*')
                        bombastic++;
                    if (j + 1 < c && rows[i + 1][j + 1] == '*')
                        bombastic++;
                }
            }
            if (bombastic)
                rows[i][j] = (char)((int)'0' + (bombastic));
        }
    }
    forN(i, r) cout << rows[i] << endl;