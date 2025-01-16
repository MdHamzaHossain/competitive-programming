#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int N;
        cin >> N;
        string s = ".141592653589793238462643383279";
        cout << s[N] << endl;
    }

    return 0;
}