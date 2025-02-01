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
    testCase
    {
        int keys;
        SCANINT(keys);
        // cout << "  KEYS " << keys << endl;
        vi keyVal = vi(0, keys);
        FORN(i, 0, keys)
        {
            int t;
            SCANINT(t);
            keyVal.push_back(t);
            // cout << "val " << i << " " << t << endl;
        }
        FORN(i, 0, keys)
        {
            int t;
            SCANINT(t);
            string s;
            cin >> s;
            for (auto c : s)
            {
                if (c == 'D')
                {
                    if (keyVal[i] == 9)
                        keyVal[i] = 0;
                    else
                        keyVal[i]++;
                }
                else
                {
                    if (keyVal[i] == 0)
                        keyVal[i] = 9;
                    else
                        keyVal[i]--;
                }
            }
            // FORN(j, 0, t)
            // {
            //     char c;
            //     SCANCH(c);
            //     cout << "DEBUG " << keys << " t " << t << " " << i << " " << j << " " << c << endl;
            //     if (c == 'U')
            //     {
            //         if (keyVal[i] == 9)
            //             keyVal[i] = 0;
            //         else
            //             keyVal[i]++;
            //     }
            //     else
            //     {
            //         if (keyVal[i] == 0)
            //             keyVal[i] = 9;
            //         else
            //             keyVal[i]--;
            //     }
            // }
        }
        FORN(i, 0, keys)
        {
            PRINTINT(keyVal[i]);
            PRINTSTR(" ");
        }
        PRINTEND;
    }
}