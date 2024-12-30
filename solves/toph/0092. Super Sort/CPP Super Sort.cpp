#include <bits/stdc++.h>
using namespace std;
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int te;
            cin >> te;
            arr.push_back(te);
        }
        sort(arr.begin(), arr.end(), [](int a, int b) -> bool
             { return (a < b); });
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1 && (arr[i + 1] - arr[i] > k))
            {
                cout << "No Solution" << endl;
                valid = false;
                break;
            }
        }
        if (!valid)
            continue;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i];
            if (i != arr.size() - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}