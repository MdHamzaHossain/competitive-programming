#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    bool isPrime = true;
    if (N == 0 || N == 1)
    {
        isPrime = false;
    }
    else
    {
        for (int i = 2; i < N; i++)
        {
            if (N % i == 0)
                isPrime = false;
        }
    }
    cout << (isPrime ? "Yes" : "No") << endl;
}