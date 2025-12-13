#include <stdio.h>
#define ll long long
#define SCANLL(A) scanf("%lld", &A)
#define PRINTEND printf("\n")
#define PRINTSTR(A) printf("%s", (A))
int main()
{
    ll a, b, c;
    SCANLL(a);
    SCANLL(b);
    SCANLL(c);
    int res = 0;
    if (b <= a)
        res = 0;
    else if (b > a && c > a)
        res = 0;
    else if ((b > c ? c : b) == c)
        res = 1;
    PRINTSTR(res ? "Ice-cream" : "Chocolate");
    PRINTEND;
    return 0;
}