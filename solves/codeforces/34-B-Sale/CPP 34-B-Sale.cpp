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

// int searchInsert(vector<int>& nums, int target) {
// return binarySearchOrPosition(nums, target);
// return

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tvs;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        tvs.push_back(t);
    }
    sort(tvs.begin(), tvs.end());
    int earn = 0;
    for (int i = 0; i < m; i++)
    {
        if (tvs[i] > 0)
            break;
        earn -= tvs[i];
    }
    cout << earn << endl;
}