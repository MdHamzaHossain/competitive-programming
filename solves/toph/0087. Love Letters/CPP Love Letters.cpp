#define ll long long
#define ull unsigned long long
#define ulli unsigned long long int
#define b2e(a) a.begin(), a.end()
#define e2b(a) a.rbegin(), a.rend()
#define forI(i, a, b) for (int i = a; i <= b; i++)
#define rforI(i, a, b) for (int i = a; i >= b; i--)
#define forN(i, b) for (int i = 0; i < b; i++)
#define rforN(i, a, b) for (int i = a; i > b; i--)
#define nTimes(i, n) for (int i = 1; i <= n; i++)
#define testCase                         \
    int testCaseAmount, currentTestCase; \
    cin >> testCaseAmount;               \
    for (currentTestCase = 1; currentTestCase <= testCaseAmount; currentTestCase++)
#define caseCout(i) cout << "Case " << currentTestCase << ": " << i << endl;
#include <bits/stdc++.h>
using namespace std;
#define mx 7368789
vector<bool> prime(mx, true);
int primeNums[mx];

void sieve(int n)
{
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main()
{
    // https://toph.co/p/love-letters
    string alphas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    sieve(100200);
    testCase
    {
        int mapArr[27];
        memset(mapArr, 0, sizeof(mapArr));
        int n;
        string s;
        cin >> n;
        cin >> s;
        for (auto c : s)
        {
            int ind = alphas.find(c);
            mapArr[ind]++;
        }
        cout << "Case " << currentTestCase << ":" << endl;
        int letters = 0;
        for (int i = 0; i < 26; i++)
        {
            if (prime[mapArr[i]])
            {
                letters++;
                cout << alphas[i] << " = " << mapArr[i] << endl;
            }
        }
        if (!letters)
            cout << "Love is painful !" << endl;
    }
}