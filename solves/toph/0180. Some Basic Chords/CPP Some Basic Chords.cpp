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
int main()
{
    map<string, string> chordMap = {
        {"x54321~~~~~~111111110001~~~~~~", "A-major"},
        {"x54321~~~~~~111111111101~~~~~~111111110011~~~~~~", "A-minor"},
        {"xx4321~~~~~~111111111110~~~~~~111111111101~~~~~~111111110011~~~~~~", "B-minor"},
        {"x54321~~~~~~111111111101~~~~~~111111110111~~~~~~111111101111~~~~~~", "C-major"},
        {"xx4321~~~~~~111111111110~~~~~~111111111011~~~~~~111111111101~~~~~~", "D-minor"},
        {"xx4321~~~~~~111111111010~~~~~~111111111101~~~~~~", "D-major"},
        {"654321~~~~~~111111111011~~~~~~111111100111~~~~~~", "E-major"},
        {"654321~~~~~~111111100111~~~~~~", "E-minor"},
        {"x54321~~~~~~111111111101~~~~~~111111111011~~~~~~111111100111~~~~~~", "F-major"},
        {"654321~~~~~~111111101111~~~~~~111111011100~~~~~~", "G-major"},
    };
    testCase
    {
        string s = "";
        int n;
        SCANINT(n);
        FORN(i, 0, n)
        {
            string s1;
            cin >> s1;
            s += s1;
        }
        // cout << "DEBUG\n\n"
        //    << s << '\n\n' << chordMap[s] << endl;
        caseCout(cout << (chordMap[s]));
    }
}
