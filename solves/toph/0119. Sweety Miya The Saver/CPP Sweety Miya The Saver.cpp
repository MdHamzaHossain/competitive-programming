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

vector<int> vec;
int f[10002];
void precal()
{
    for (int i = 2; i <= 10000; i++)
    {
        if (f[i] == 0)
            vec.push_back(i);
        for (int j = i + i; j <= 10000; j += i)
            f[j] = 1;
    }
}
int main()
{

    precal();
    testCase
    {
        int n, res = 0;
        string s;
        cin >> n >> s;
        bool x = false;
        for (int i = 0; i < s.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < i + 4; j++)
            {
                sum *= 10;
                sum += (s[j] - '0');
                if (f[sum] == 0)
                    res = max(res, sum);
            }
        }
        if (res == 0)
        {
            caseCout(printf("This is a junk!"));
        }
        else
        {
            caseCout(printf("%d", res));
        }
    }

    return 0;
}