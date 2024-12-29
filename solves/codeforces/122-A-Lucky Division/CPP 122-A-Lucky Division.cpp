#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int luckiesTillThou[] = {4, 7, 47, 74, 447, 474, 477, 744, 747, 774};
    bool almostLucky = false;
    for (int i = 0; i < 10; i++)
    {
        if ((n % luckiesTillThou[i]) == 0)
        {
            almostLucky = true;
            break;
        };
    }
    cout << (almostLucky ? "YES" : "NO") << endl;
}