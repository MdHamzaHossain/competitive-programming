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

int main()
{
    string s;
    getline(cin, s);
    int words = 1;
    for (auto c : s)
        words += (c == ' ');
    int t;
    SCANINT(t);
    vector<string> peeps;
    vector<vector<string>> teams = vector<vector<string>>(2, vector<string>(0));
    int team = 0;
    FORN(i, 0, t)
    {
        string s;
        cin >> s;
        peeps.push_back(s);
        // cout << "DEBUG " << s << " " << peeps[i] << ENDL;
    }
    int i = 0;
    int j = 1;
    while (1)
    {
        // cout << " DEBUG " << "WORD:" << words << " " << peeps.size() << " i:" << i << " j:" << j << " t:" << t << " " << peeps[i] << endl;

        if (j == words)
        {
            // cout << "ERASING " << peeps[i] << ENDL;
            teams[team].push_back(peeps[i]);
            team = !team;

            peeps.erase(peeps.begin() + i);
            // cout << "ERASED " << !team << " " << teams[!team][0] << " size " << peeps.size() << endl;
            // cout << "   DEBUG " << peeps.size() << " " << i << " " << t << peeps[i] << endl;
            j = 1;
        }
        else
        {

            j++;
            i++;
        }
        if (i >= peeps.size())
            i = 0;
        if (peeps.size() == 0)
            break;
    }
    // cout << "BRUH" << ENDL;
    PRINTINT(teams[0].size());
    PRINTEND;
    FORN(i, 0, teams[0].size())
    {
        cout << teams[0][i] << ENDL;
    }
    // for (auto a : teams[0])
    // {
    //     cout << (a);
    //     cout << teams[0][0];
    //     PRINTEND;
    // }
    PRINTINT(teams[1].size());
    PRINTEND;

    for (auto a : teams[1])
    {
        cout << (a);
        PRINTEND;
    }
}