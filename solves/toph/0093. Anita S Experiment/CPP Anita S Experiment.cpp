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

        int n;
        cin >> n;

        int allGoodCount = 0;
        int allBadCount = 0;
        int specialDayCount = 0;
        int equalsCount = 0;
        int prevValue;
        cin >> prevValue;
        int secondPrevValue = prevValue;
        int lastSpecial = -1;
        int maxSpecial = 0;
        forN(i, 1, n)
        {
            int day;
            cin >> day;
            if (day == prevValue)
                equalsCount++;
            if (day >= prevValue)
                allGoodCount++;
            if (day <= prevValue)
                allBadCount++;
            if (day < prevValue && prevValue > secondPrevValue)
            {
                specialDayCount++;
                if (lastSpecial == -1)
                    lastSpecial = i;
                else
                {
                    maxSpecial = max(maxSpecial, i - lastSpecial - 1);
                    // cout << "SPECIAL " << i << " LAST " << lastSpecial << " nax " << maxSpecial << endl;
                    lastSpecial = i;
                }
            }

            secondPrevValue = prevValue;
            prevValue = day;
        }
        // cout << "n " << n << " equals " << equalsCount << " good " << allGoodCount << " bad " << allBadCount << " specials " << specialDayCount << endl;
        if (equalsCount == n - 1)
            cout << "neutral" << endl;
        else if (n - 1 == allGoodCount)
            cout << "allGoodDays" << endl;
        else if (n - 1 == allBadCount)
            cout << "allBadDays" << endl;
        else
        {
            cout << (maxSpecial > 0 ? to_string(maxSpecial) : "none") << endl;
        }
    }
}