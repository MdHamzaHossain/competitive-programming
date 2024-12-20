#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    n -= 2;
    printf("%s\n", ((n > 1 && n % 2 == 0) ? "YES" : "NO"));
    return 0;
}
