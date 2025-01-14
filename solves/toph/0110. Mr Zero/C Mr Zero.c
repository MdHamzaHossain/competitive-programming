#include <stdio.h>
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
    int r, c;
    SCANINT(r);
    SCANINT(c);
    int matrix[r][c];
    int rowsMatch[r];
    int columnsMatch[c];
    FORN(i, 0, r)
    {
        FORN(j, 0, c)
        {
            int t;
            SCANINT(matrix[i][j]);
            // cout << "DEBUG " << matrix[r][c] << ENDL;
        }
    }
    int count = 0;

    FORN(i, 0, r)
    {
        int prev = matrix[i][0];
        int valid = 1;

        FORN(j, 1, c)
        {
            // cout << " DEB " << prev << " " << matrix[i][j] << ENDL;
            if (prev != matrix[i][j])
            {
                valid = 0;
                break;
            }
        }
        rowsMatch[i] = valid;
        count += valid;
    }
    FORN(i, 0, c)
    {
        int valid = 1;
        int prev = matrix[0][i];
        FORN(j, 1, r)
        {
            if (prev != matrix[j][i])
            {
                valid = 0;
                break;
            }
        }
        count += valid;
        columnsMatch[i] = valid;
    }
    count = 0;
    FORN(i, 0, r)
    {
        FORN(j, 0, c)
        {
            // cout << j << " " << rowsMatch[i] << ENDL;
            count += rowsMatch[i] && columnsMatch[j];
        }
    }
    PRINTINT(count);
    PRINTEND;
}