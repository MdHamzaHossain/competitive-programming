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
    int n;
    string s;
    cin >> n >> s;

    bool valid = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (i != n - 1 && s[i] == s[i + 1])
            valid = false;
    }
    cout << (valid ? "No change needed" : "Change needed") << endl;
}