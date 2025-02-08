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

int main1()
{
    map<string, int> val;
    string tmr = "Timur";
    val[tmr] = 1;
    while (next_permutation(b2e(tmr)))
    {
        val[tmr] = 1;
    }
    testCase
    {
        int n;
        SCANINT(n);
        string s;
        cin >> s;
        int valid = 1;
        map<char, int> charTrack;

        if (s.size() != tmr.size())
        {
            valid = 0;
        }
        else
        {
            for (auto c : s)
            {
                charTrack[c]++;
                // cout << "DEBUG " << c << " " << charTrack[c] << endl;
                if (c != 'T' && c != 'i' && c != 'm' && c != 'u' && c != 'r')
                {
                    valid = 0;
                    break;
                }
                if (charTrack[c] != 1)
                {
                    valid = 0;
                    break;
                }
            }
        }

        PRINTSTR((valid ? "YES" : "NO"));
        PRINTEND;
    }
}
/**
 * Implimentation 2
 */
int main()
{
    map<string, int> val;
    string tmr = "Timru";
    val[tmr] = 1;
    while (next_permutation(b2e(tmr)))
    {
        val[tmr] = 1;
    }
    testCase
    {
        int n;
        SCANINT(n);
        string s;
        cin >> s;
        int valid = 1;
        if (s.size() != tmr.size() || val[s] != 1)
        {
            valid = 0;
        }
        PRINTSTR((valid ? "YES" : "NO"));
        PRINTEND;
    }
}