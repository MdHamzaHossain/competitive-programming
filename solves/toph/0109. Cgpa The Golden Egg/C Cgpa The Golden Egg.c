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

    testCase
    {
        int n;
        SCANINT(n);
        double totalGrade = 0;
        double totalCred = 0;
        int failed = 0;
        while (n--)
        {
            double a, c;
            SCANDOUBLE(a);
            SCANDOUBLE(c);
            if (a < 40)
            {
                failed++;
                continue;
            }
            totalCred += c;
            if (a < 40)
                a = 0.0;
            else if (a < 45)
                a = 2.0;
            else if (a < 50)
                a = 2.25;
            else if (a < 55)
                a = 2.5;
            else if (a < 60)
                a = 2.75;
            else if (a < 65)
                a = 3.0;
            else if (a < 70)
                a = 3.25;
            else if (a < 75)
                a = 3.5;
            else if (a < 80)
                a = 3.75;
            else
                a = 4.00;
            totalGrade += a * c;
        }

        // PRINTSTR("Case " + to_string(currentTestCase) + ": ");
        PRINTSTR("Case ");
        PRINTINT(currentTestCase);
        PRINTSTR(": ");
        if (failed)
        {
            PRINTSTR("Sorry, you have failed in ");
            PRINTINT(failed);
            PRINTSTR(" course");
            if (failed > 1)
                PRINTSTR("s");
            PRINTSTR("!");
        }
        else
            printf("%.2lf", (totalGrade / totalCred));
        PRINTEND;
    }
}