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
    vi a;
    vi b;
    char c = '.';
    string s1, s2;
    cin >> s1 >> s2;
    string t = "";
    for (auto c : s1)
    {
        if (c != '.')
            t += c;
        else
        {
            a.push_back(stoi(t));
            t = "";
        }
    }
    a.push_back(stoi(t));
    t = "";
    for (auto c : s2)
    {
        if (c != '.')
            t += c;
        else
        {
            b.push_back(stoi(t));
            t = "";
        }
    }
    b.push_back(stoi(t));

    // for (auto e : b)
    //     cout << e << endl;
    // int a1, a2, a3, b1, b2, b3;
    // int a[3], b[3];
    // char c;
    // SCANINT(a[0]);
    // SCANCH(c);
    // SCANINT(a[1]);
    // SCANCH(c);
    // SCANINT(a[2]);

    // SCANINT(b[0]);
    // SCANCH(c);
    // SCANINT(b[1]);
    // SCANCH(c);
    // SCANINT(b[2]);
    int big = 1;
    FORN(i, 0, max(a.size(), b.size()))
    {
        if (b[i] == a[i])
            continue;
        if (b[i] > a[i])
        {
            big = 2;
            break;
        }
        if (a[i] > b[i])
        {
            big = 1;
            break;
        }
    }
    if (big == 2)
        swap(a, b);
    cout << ((big == 2) ? s2 : s1) << ENDL;
    // PRINTSTR((big == 2) ? s2 : s1);
    // printf("%d.%d.%d", a[0], a[1], a[2]);
}