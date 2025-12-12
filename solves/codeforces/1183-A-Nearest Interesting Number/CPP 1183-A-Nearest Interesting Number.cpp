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

int main()
{
    ll n;
    SCANLL(n);
    vll v = {0, 4, 8, 13, 17, 22, 26, 31, 35, 39, 40, 44, 48, 53, 57, 62, 66, 71, 75, 79, 80, 84, 88, 93, 97, 103, 107, 112, 116, 121, 125, 129, 130, 134, 138, 143, 147, 152, 156, 161, 165, 169, 170, 174, 178, 183, 187, 192, 196, 202, 206, 211, 215, 219, 220, 224, 228, 233, 237, 242, 246, 251, 255, 259, 260, 264, 268, 273, 277, 282, 286, 291, 295, 299, 301, 305, 309, 310, 314, 318, 323, 327, 332, 336, 341, 345, 349, 350, 354, 358, 363, 367, 372, 376, 381, 385, 389, 390, 394, 398, 400, 404, 408, 413, 417, 422, 426, 431, 435, 439, 440, 444, 448, 453, 457, 462, 466, 471, 475, 479, 480, 484, 488, 493, 497, 503, 507, 512, 516, 521, 525, 529, 530, 534, 538, 543, 547, 552, 556, 561, 565, 569, 570, 574, 578, 583, 587, 592, 596, 602, 606, 611, 615, 619, 620, 624, 628, 633, 637, 642, 646, 651, 655, 659, 660, 664, 668, 673, 677, 682, 686, 691, 695, 699, 701, 705, 709, 710, 714, 718, 723, 727, 732, 736, 741, 745, 749, 750, 754, 758, 763, 767, 772, 776, 781, 785, 789, 790, 794, 798, 800, 804, 808, 813, 817, 822, 826, 831, 835, 839, 840, 844, 848, 853, 857, 862, 866, 871, 875, 879, 880, 884, 888, 893, 897, 903, 907, 912, 916, 921, 925, 929, 930, 934, 938, 943, 947, 952, 956, 961, 965, 969, 970, 974, 978, 983, 987, 992, 996, 1003, 1007};
    cout << *lower_bound(b2e(v), n) << endl;
}
