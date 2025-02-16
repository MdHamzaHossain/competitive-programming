#include <bits/stdc++.h>

using namespace std;
int main()
{
    double a, r1, r2, r3, r4, t, pi = acos(-1);
    while (scanf("%lf %lf %lf %lf %lf", &a, &r1, &r2, &r3, &r4) != EOF)
    {
        t = a * a;
        printf("%.3lf\n", t - (pi * r1 * r1 / 4 + pi * r2 * r2 / 4 + pi * r3 * r3 / 4 + pi * r4 * r4 / 4));
    }
    return 0;
}