#include <stdio.h>
#include <math.h>
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
    testCase
    {
        int n;
        SCANINT(n);
        char s1[n + 1];
        char s2[n + 1];
        SCANSTR(s1);
        SCANSTR(s2);

        int res = -1;
        for (int i = 0; i < n; i++)
        {
            if (s2[i] == s1[0])
            {
                int valid = 1;
                for (int j = 1; j < n; j++)
                {
                    int ind1 = j;
                    int ind2 = i + j >= n ? (i + j) - n : i + j;
                    if (s1[j] != s2[ind2])
                        valid = 0;
                }
                if (valid)
                    res = (i < n - i) ? i : n - i;
            }
        }
        PRINTINT(res);
        PRINTEND;
    }
}