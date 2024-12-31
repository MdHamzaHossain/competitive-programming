#include <stdio.h>

int main()
{
    int a, b, t;
    char c;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &a, &b);
        scanf("%c", &c);
        printf("%d ", a + b);
    }

    return 0;
}