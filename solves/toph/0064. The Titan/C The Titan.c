#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int sum = 0;
    N++;
    while (N--)
    {
        sum += N * N;
    }
    printf("%d\n", sum);
}