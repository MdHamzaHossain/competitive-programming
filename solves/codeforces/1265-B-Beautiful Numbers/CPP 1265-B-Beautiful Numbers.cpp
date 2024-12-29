
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int si;
        cin >> si;
        vector<int> arr;
        int weTheOnes;
        vector<int> res = vector<int>(si + 1, 0);
        map<int, int> indexMapper;
        for (int i = 0; i < si; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
            if (temp == 1)
            {
                weTheOnes = i;
            }
            indexMapper[temp] = i + 1;
        }
        int maxim = indexMapper[1];
        int minim = indexMapper[1];
        // starts with 1
        res[1] = 1;
        for (int i = 2; i < si; i++)
        {
            maxim = max(maxim, indexMapper[i]);
            minim = min(minim, indexMapper[i]);
            if ((maxim - minim + 1) == i)
            {
                res[i] = 1;
            }
        }

        for (int i = 1; i < res.size() - 1; i++)
            cout << res[i];
        // ends with 1
        cout << 1;
        cout << endl;
    }
    return 0;
}
/**
* LINEAR
int beautifulNumbers(int n1, int s1i, vector<int> a1rr)
{
    int n;
    cin >> n;
    while (n--)
    {
        int si;
        cin >> si;
        vector<int> arr;
        int weTheOnes;
        vector<int> res = vector<int>(si + 1, 0);
        for (int i = 0; i < si; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
            if (temp == 1)
            {
                weTheOnes = i;
            }
        }
        int maxim = 0;
        int minim = INT_MAX;
        for(int i=0; i < si; i++){
            maxim = max(maxim, arr[i]);
            minim = min(minim, arr[i]);
            if(maxim - minim +1 == i)
            res.at(i) = 1;
        }

        int l = weTheOnes + 1;
        int l1 = l;
        while (l--)
        {
            int r = weTheOnes;

            for (r; r < si; r++)
            {
                int count = 0;
                int bigger = 0;
                for (int j = l; j <= r; j++)
                {
                    if (arr[j] > (r - l + 1))
                    {
                        bigger = arr[j];
                        break;
                    }
                    count++;
                }
                int indo = r - l + 1;
                if (count != indo)
                {
                    // skip a lot of iterations;
                    r += (bigger - indo - 1);
                    continue;
                };
                cout << count << " " << indo << endl;
                res[indo] = 1;
            };
        }
        for (int i = 1; i < res.size(); i++)
            cout << res[i];
        cout << endl;
    }
    // your code goes here
}
*/