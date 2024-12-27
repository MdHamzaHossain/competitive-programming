#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long int m, n, a;
    cin >> m >> n >> a;
    // need to do it separately lol
    a = ceil(((double)m / a)) * ceil(((double)n / a));
    cout << a << endl;
}