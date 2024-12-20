#include <iostream>
#include <cmath>
using namespace std;

long long int func(long long int a, long long int x)
{
    return (x / a) + (x % a);
}
long long int findLastDivisor(long long int up, long long int bot, long long int a)
{
    if (bot == up)
        return up;
    // for(long long int i=up; i>=bot;i--) if(i%a==0 && ((i-1) >=bot)) return i;
    return ((up / a) * a);
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        long long int l, r, a, res, lastDiv;
        cin >> l >> r >> a;
        res = r;
        lastDiv = findLastDivisor(r, l, a) - 1;
        // if the last divisor is in the range
        if (lastDiv >= l)
            res = lastDiv;
        cout << max(func(a, r), func(a, res)) << endl;
    }
    return 0;
}