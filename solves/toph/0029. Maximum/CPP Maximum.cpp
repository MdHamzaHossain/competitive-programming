#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int biggest = 0;
    int A[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        if (A[i] > biggest)
            biggest = A[i];
    }
    cout << biggest;

    return 0;
}