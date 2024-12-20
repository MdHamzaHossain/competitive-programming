#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int i = 1;
    while (T--)
    {
        int A, C;
        char B;
        int R;
        cin >> A >> B >> C;
        switch (B)
        {

        case '+':
            R = A + C;
            break;
        case '-':
            R = A - C;
            break;
        case '*':
            R = A * C;
            break;
        }
        cout << "Case " << i << ": " << R << endl;
        i++;
    }

    return 0;
}