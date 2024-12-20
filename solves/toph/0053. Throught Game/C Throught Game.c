#include <stdio.h>
#include <math.h>

int main()
{
    int T, avg, X, Y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &X, &Y);
        avg = (X + Y) / 2;
        if (avg % 2 == 0)
            printf("Sadia will be happy.\n");
        else
            printf("Oops!\n");
    }
    return 0;
}