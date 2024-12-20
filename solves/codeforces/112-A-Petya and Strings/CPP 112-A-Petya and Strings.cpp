#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int N;
    string S1;
    string S2;

    cin >> S1;
    cin >> S2;
    for (int i = 0; i < S1.size(); i++)
    {
        char charOf1 = toupper(S1[i]);
        int charOf2 = toupper(S2[i]);
        // cout << charOf1 << endl;
        // cout << toupper(S1[i]) << " " << toupper(S2[i])<< endl;
        if (charOf1 < charOf2)
        {
            cout << -1 << endl;
            return 0;
        }
        else if (charOf1 > charOf2)
        {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}