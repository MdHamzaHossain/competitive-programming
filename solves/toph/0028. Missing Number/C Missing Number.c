#include <stdio.h>

int main()
{
    int t, a, b, c;
    scanf("%d", &t);
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", t - a - b - c);
}