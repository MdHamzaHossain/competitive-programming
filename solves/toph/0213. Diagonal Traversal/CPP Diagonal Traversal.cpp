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
        ll n, m;
        SCANLL(n);
        SCANLL(m);
        if (m < n)
            swap(m, n);

        int valid = 1;
        // valid = ((n==1) && m == 1) || (n >= 4) || (n == 4 && ((m>=5 && (m-5)%8==0)) ||(n == 5 && ( (m>=10&&(m-10)%2==0 )) || (n==6 && ((m>=11&&(m-11)%2==0));
        if (n == 1)
        {

            if (m != 1)
                valid = 0;
        }
        else if (n < 4)
            valid = 0;
        else if (n == 4)
        {
            if (((m >= 5 && (m - 5)) % 8 != 0))
                valid = 0;
        }
        else if (n == 5)
        {

            if (((m >= 10 && (m - 10)) % 2 != 0))
                valid = 0;
        }
        else if (n == 6)
        {
            if ((m >= 11 && (m - 11)) % 2 != 0)
                valid = 0;
        }

        caseCout(PRINTSTR((valid ? "YES" : "NO")));
        // PRINTEND;
    }
}
