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

class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int nSize = nums.size();
        int qSize = queries.size();
        pair<vector<int>, vector<vector<int>>> tracker = {nums, queries};

        vector<bitset<1010>> cache(nSize);
        FORN(i, 0, nSize)
        {
            cache[i].reset();
            cache[i].set(0, true);
        }

        bool weZeroes = true;
        FORN(j, 0, nSize)
        {
            if (nums[j] != 0)
            {
                weZeroes = false;
                break;
            }
        }

        if (weZeroes)
            return 0;
        FORN(i, 0, qSize)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][2];

            for (int j = l; j <= r; j++)
            {
                cache[j] |= (cache[j] << v);
                FORN(k, nums[j] + 1, 1010)
                {
                    cache[j].reset(k);
                }
            }

            bool valid = true;
            FORN(j, 0, nSize)
            {
                if (!cache[j].test(nums[j]))
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
                return i + 1;
        }

        return -1;
    }
};