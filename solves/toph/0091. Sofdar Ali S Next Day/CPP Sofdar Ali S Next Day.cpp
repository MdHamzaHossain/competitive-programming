#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int totalDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < n; i++)
    {
        int d, m, y;
        cin >> d >> m >> y;
        d++;
        if (d > totalDays[m] && !(d == 29 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))))
        {
            if ((m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))))
            {
                if (d == 30)
                {
                    d = 1;
                    m++;
                }
            }
            else if (m == 12)
            {
                d = 1;
                m = 1;
                y++;
            }
            else
            {
                d = 1;
                m++;
            }
        }
        if (d < 10)
            cout << '0';
        cout << d << " " << months[m] << ", " << y << endl;
    }
    return 0;
}