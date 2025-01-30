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
    PRINTSTR("Case #");       \
    PRINTLL(currentTestCase); \
    PRINTSTR(": ");           \
    if (1)                    \
        i;                    \
    PRINTEND;

int main()
{
    // FAST;
    testCase
    {
        ll n, l;
        SCANLL(n);
        SCANLL(l);
        vi v;
        FORN(i, 0, n)
        {
            ll t;
            SCANLL(t);
            v.push_back(t);
        }
        sort(b2e(v));
        ll res = -1;
        ll count = 1;

        for (ll i = 1; i < n;)
        {
            if (v[i] - v[i - 1] <= l)
            {
                i++;
                count++;
            }
            else
            {
                res = max(res, count);
                count = 1;
                i++;
            }
        }
        res = max(res, count);
        PRINTLL((n - res));
        PRINTEND;
    }
}

// int main()
// {
//     testCase
//     {
//         string s;
//         cin >> s;
//         vector<int> s1;
//         vector<int> s2;
//         for (auto c : s)
//         {
//             s1.push_back(c - '0');
//             s2.push_back(c - '0');
//         }
//         int swaps = 2;
//         auto prev = s1.begin();
//         for (auto itr = s1.begin() + 1; itr != s1.end(); itr++)
//         {
//             prev = itr;

//             if (*itr > *prev)
//             {
//                 swap(itr, prev);
//                 swaps--;
//                 if (!swaps)
//                     break;
//             }
//         }
//         swaps = 2;
//         prev = s2.end();
//         for (auto itr = s2.end() - 1; itr != s2.begin(); itr--)
//         {
//             prev = itr;

//             if (*prev < *itr)
//             {
//                 swap(itr, prev);
//                 swaps--;
//                 if (!swaps)
//                     break;
//             }
//         }
//         vector<int> largest = s1;

//         for (int i = 0; i < s1.size(); i++)
//         {
//             if (s1[i] == s2[i])
//                 continue;
//             else if (s1[i] > s2[i])
//             {
//                 largest = s1;
//                 break;
//             }
//             else if (s1[i] < s2[i])
//             {
//                 largest = s2;
//                 break;
//             }
//         }
//         for (auto i : largest)
//         {
//             cout << i;
//         }
//         cout << ENDL;
//     }
// }
