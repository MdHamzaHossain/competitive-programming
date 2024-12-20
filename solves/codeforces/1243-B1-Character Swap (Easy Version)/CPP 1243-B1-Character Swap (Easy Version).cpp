#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int l;
        cin >> l;
        string s, t;
        cin >> s >> t;
        int diffCount = 0;
        int diffPos[] = {-1, -1, -1};

        int can = 0;
        for (int i = 0; i < l; i++)
        {
            if (s[i] != t[i])
            {
                diffPos[diffCount] = i;
                diffCount++;
            }
            if (diffCount > 2)
                break;
        }
        if (diffCount == 2)
        {
            int pos1 = diffPos[0];
            int pos2 = diffPos[1];

            string temp1 = s.substr(0);
            temp1[pos1] = t[pos2];

            string temp2 = t.substr(0);
            temp2[pos2] = s[pos1];

            if (temp1 == temp2)
                can = 1;
        }
        cout << (can ? "Yes" : "No") << endl;
    }
}