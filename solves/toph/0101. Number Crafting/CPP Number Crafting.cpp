#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;
        // SCANINT(m);
        vector<int> nums;
        int te;
        cin >> te;
        nums.push_back(te);
        int sum = nums[0];
        int mn = nums[0];

        for (int i = 1; i < m; i++)
        {
            cin >> te;
            nums.push_back(te);
            sum += te;
            mn = min(mn, te);
        }

        int target = sum / mn;
        vector<int> found;
        for (int i = 0; i < m; i++)
        {
            if (nums[i] == target)
                found.push_back(i + 1);
        }

        if (found.size() < 1)
            cout << ("NULL\n");
        else
        {
            for (int i = 0; i < found.size(); i++)
            {
                cout << (found[i]);

                if (i < found.size() - 1)
                    cout << (" ");
            }
            cout << endl;
        }
    }
}