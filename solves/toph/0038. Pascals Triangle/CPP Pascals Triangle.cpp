#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << (int)pow(2, N == 0 ? 0 : N - 1) << endl;
}