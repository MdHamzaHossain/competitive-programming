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
#define testCase                         \
    int testCaseAmount, currentTestCase; \
    SCANINT(testCaseAmount);             \
    for (currentTestCase = 1; currentTestCase <= testCaseAmount; currentTestCase++)
#define caseCout(i) cout << "Case " << currentTestCase << ": " << i << ENDL;

int main()
{
    FAST;
    ll N, M;
    SCANLL(N);
    SCANLL(M);
    vector<ll> packageAmount;
    vector<ll> packagePrice;
    NTIMES(i, M)
    {
        ll t;
        SCANLL(t);
        packageAmount.push_back(t);
    }
    NTIMES(i, M)
    {
        ll t;
        SCANLL(t);
        packagePrice.push_back(t);
    }
    ll sum = 0;
    NTIMES(i, N)
    {
        ll t;
        SCANLL(t);
        sum += t;
    }
    ll maxAmount = (sum - packageAmount[0] * N) - packagePrice[0];
    FORN(i, 1, M)
    {
        maxAmount = max(maxAmount, sum - packageAmount[i] * N - packagePrice[i]);
    }
    if (maxAmount == 0)
        PRINTSTR("Neutral");
    else
    {
        if (maxAmount > 0)
            PRINTSTR("Profit ");
        else
            PRINTSTR("Loss ");
        PRINTLL(abs(maxAmount));
    }
    PRINTEND;
}