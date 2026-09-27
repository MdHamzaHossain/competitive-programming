#include <bits/stdc++.h>
using namespace std;
#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);

// cout.tie(0);
#define cinline(s) getline(cin, s)
#define ENDL "\n"
#define SCANINT(A) scanf("%d", &A)
#define SCANDOUBLE(A) scanf("%lf", &A)
#define SCANSTR(A) scanf("%s", A)
#define SCANCH(A) scanf("%c", &A)
#define SCANLL(A) scanf("%lld", &A)
#define SCANLD(A) scanf("%Lf", &A)
#define PRINTINT(A) printf("%d", (A))
#define PRINTDOUBLE(A) printf("%lf", (A))
#define PRINTSTR(A) printf("%s", (A))
#define PRINTCH(A) printf("%c", (A))
#define PRINTLL(A) printf("%lld", (A))
#define PRINTLD(A) printf("%Lf", (A))
#define PRINTEND printf("\n")
typedef long long ll;
typedef unsigned long long int ulli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pairInt;
typedef pair<ll, ll> pairLL;
#define MP make_pair
#define PB push_back
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
#define case
// Cout(i)           \
    PRINTSTR("Case ");        \
    PRINTLL(currentTestCase); \
    PRINTSTR(": ");           \
    if (1)                    \
        i;                    \
    PRINTEND;
#define MATHPI acos(-1)
#define MOD 1000000007
inline void normal(ll &a)
{
    if (abs(a) >= MOD)
        a %= MOD;
    (a < 0) && (a += MOD);
}
inline ll modMul(ll a, ll b)
{
    normal(a), normal(b);
    return (a * b) % MOD;
}
inline ll modAdd(ll a, ll b)
{
    normal(a), normal(b);
    return (a + b) % MOD;
}
inline ll modSub(ll a, ll b)
{
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
inline ll modPow(ll b, ll p)
{
    ll r = 1;
    b %= MOD;
    while (p)
    {
        if (p & 1)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1;
    }
    return r;
}
inline ll modInverse(ll a) { return modPow(a, MOD - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll gcd(ll a, ll b) { return __gcd(a, b); }

int main()
{
    ll n;
    SCANLL(n);
    stack<string> st;

    string err;
    bool done = 0;
    int expFoundAt = -1;
    FORN(i, 0, n + 1)
    {
        string s;
        cinline(s);

        stringstream words(s);
        string word;

        //  cout << i << ": " << endl;
        if (done)
            break;
        /**
         * 0 default
         * 1 catch block
         * 2 throw
         */
        int mode = 0;
        while (words >> word)
        {
            if (done)
                break;
            if (word == "try")
            {
                st.push(word);
            }
            else if (word.find("catch") == 0)
            {

                // cout << "Catch for " << st.size() << endl;
                if (st.size() > expFoundAt)
                {
                    // cout << "Broke out of catch " << st.size() << " because exp found at " << expFoundAt << endl;
                    st.pop();
                    break;
                }
                mode = 1;

                break;
            }
            else if (word.find("throw") == 0)
            {
                expFoundAt = st.size();

                // cout << "exp found at " << expFoundAt << endl;
                mode = 2;
                break;
            }
        }
        if (mode == 1)
        {
            string mess = "";
            string exType = "";
            /**
             * 0 default
             * 1 exType
             * 2 trans
             * 3 errorMessage
             */
            int mode2 = 0;
            for (auto e : s)
            {
                if (mode2 != 3 && e == ' ')
                    continue;
                if (e == '(')
                {
                    mode2 = 1;
                    continue;
                }
                if (mode2 == 1)
                {

                    if (e == ',')
                    {
                        mode2 = 2;
                        continue;
                    }
                    exType += e;
                }
                if (mode2 == 3)
                {
                    if (e == '"')
                        break;
                    mess += e;
                }
                if (e == '"')
                {
                    mode2 = 3;
                    continue;
                }
            }

            //  cout << endl
            //        << exType << " _ " << '"' << mess << '"' << endl;
            if (exType == err)
            {

                cout << (mess);
                done = 1;
            }
            st.pop();
            expFoundAt--;
        }
        if (mode == 2)
        {
            /**
             * 0 default
             * 1 error
             */
            int mode2 = 0;
            for (auto e : s)
            {
                if (e == ' ')
                    continue;
                if (e == '(')
                {
                    mode2 = 1;
                    continue;
                }
                if (mode2 == 1)
                {
                    if (e == ')')
                        break;
                    err += e;
                }
            }

            //   cout << "ERROR TYPE " << err << endl;
        }
        // cin >> s;

        // cout << endl;
    }
    if (!done)
        PRINTSTR("Unhandled Exception");
    return 0;
}
