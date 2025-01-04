#include <bits/stdc++.h>
using namespace std;
#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define cinline(s) getline(cin, s);
#define ENDL "\n"
#define SCANINT(A) scanf("%d", &A);
#define SCANSTR(A) scanf("%s", &A);
#define SCANLL(A) scanf("%lld", &A);
#define SCANLD(A) scanf("%Ld", &A);
#define PRINTINT(A) printf("%d", A);
#define PRINTSTR(A) printf("%s", A);
#define PRINTLL(A) printf("%lld", A);
#define PRINTLD(A) printf("%Ld", A);
#define PRINTEND printf("\n");
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
    int t, a1, a2, b1, b2, c1, c2, d1, d2;
    SCANINT(t);
    while (t--)
    {
        SCANINT(a1);
        SCANINT(a2);
        SCANINT(b1);
        SCANINT(b2);
        SCANINT(c1);
        SCANINT(c2);
        SCANINT(d1);
        SCANINT(d2);

        int side = 0;
        if (a1 == b1)
            side = abs(a2 - b2);
        else if (a1 == c1)
            side = abs(a2 - c2);
        else if (a1 == d1)
            side = abs(a2 - d2);
        else if (a2 == b2)
            side = abs(a1 - b1);
        else if (a2 == c2)
            side = abs(a1 - c1);
        else if (a2 == d2)
            side = abs(a1 - d1);
        PRINTINT((side * side));
        PRINTEND;
    }
}