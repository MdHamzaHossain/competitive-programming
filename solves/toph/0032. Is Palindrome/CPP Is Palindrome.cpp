#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;
    string a = "";
    for (auto c : S)
    {
        a = c + a;
    }
    cout << (S == (a) ? "Yes" : "No") << endl;
    return 0;
}