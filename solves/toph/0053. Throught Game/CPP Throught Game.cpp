#include <iostream>

using namespace std;

int main()
{
    int T, Xi, Yi;
    cin >> T;

    while (T--)
    {
        cin >> Xi >> Yi;
        cout << ((((Xi + Yi) / 2) % 2 == 0) ? "Sadia will be happy." : "Oops!") << endl;
    }
    return 0;
}