#include <stdio.h>

int main()
{
    int n, a;
    scanf("%d", &n);
    int max = 0;
    while (n--)
    {
        scanf("%d", &a);
        if (a > max)
            max = a;
    }
    printf("%d", max);
}