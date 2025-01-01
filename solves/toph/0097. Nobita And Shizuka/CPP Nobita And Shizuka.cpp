#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ulli unsigned long long int
#define b2e(a) a.begin(), a.end()
#define e2b(a) a.rbegin(), a.rend()
#define forI(i, a, b) for (int i = a; i <= b; i++)
#define rforI(i, a, b) for (int i = a; i >= b; i--)
#define forN(i, a, b) for (int i = a; i < b; i++)
#define rforN(i, a, b) for (int i = a; i > b; i--)
#define nTimes(i, n) for (int i = 1; i <= n; i++)
#define testCase                         \
    int testCaseAmount, currentTestCase; \
    cin >> testCaseAmount;               \
    for (currentTestCase = 1; currentTestCase <= testCaseAmount; currentTestCase++)
#define caseCout(i) cout << "Case " << currentTestCase << ": " << i << endl;

int main()
{
    testCase
    {
        string S;
        cin >> S;
        int opened = 0;
        int zeroFromTop = 0;
        int subs = 0;
        forN(i, 0, S.length())
        {
            if (S[i] == '1')
            {
                int count = 0;
                for (int j = i + 1; j < S.length(); j++)
                {
                    if (S[j] == '0')
                    {
                        count++;
                    }
                    else
                    {
                        if (count)
                            subs++;
                        break;
                    }
                }
            }
        }
        caseCout(subs);
    }
}