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
        ll a, b, n;
        SCANLL(a);
        SCANLL(b);
        SCANLL(n);
        ll ans = b;
        FORN(i, 0, n)
        {
            ll t;
            SCANLL(t);
            ans += (t < (a - 1)) ? t : (a - 1);
        }
        PRINTLL(ans);
        PRINTEND;
    }

    return 0;
}

class Solution
{
public:
    void replaceAll(string &s, char from, char to)
    {
        for (char &c : s)
            if (c == from)
                c = to;
    }

    int maxDiff(int num)
    {

        string highestNumStr = to_string(num);
        string lowestNumStr = highestNumStr;

        for (int i = 0; i < highestNumStr.size(); ++i)
        {
            if (highestNumStr[i] != '9')
            {
                replaceAll(highestNumStr, highestNumStr[i], '9');
                break;
            }
        }

        if (lowestNumStr[0] != '1')
            replaceAll(lowestNumStr, lowestNumStr[0], '1');
        else
        {

            for (int i = 1; i < lowestNumStr.size(); ++i)
            {
                if (lowestNumStr[i] != '0' && lowestNumStr[i] != '1')
                {
                    replaceAll(lowestNumStr, lowestNumStr[i], '0');
                    break;
                }
            }
        }

        return stoi(highestNumStr) - stoi(lowestNumStr);
    }
};