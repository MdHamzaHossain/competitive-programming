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
#define SCANCH(A) scanf("%c", A)
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

int main()
{
    int n, x;
    SCANINT(n);
    SCANINT(x);
    vi v;
    FORN(i, 0, n)
    {
        int t;
        SCANINT(t);
        v.push_back(t);
    }
    sort(b2e(v), [](int a, int b) -> bool
         { return a > b; });

    int steps = 0;
    // for (auto e : v)
    // cout << e << " ";
    // cout << endl;
    while (v.size())
    {
        // cout << "step " << steps + 1 << " el ";
        // for (auto e : v)
        //     cout << e << " ";
        // cout << endl;

        int del = max(x, v[v.size() - 1]);
        for (int i = v.size() - 1; i > -1; i--)
        {
            if (v[i] <= del)
            {
                v.pop_back();
                // cout << " del " << v[i] << " " << del << endl;
            }
            else
                v[i] -= del;
        }
        steps++;
    }
    cout << steps << endl;
}