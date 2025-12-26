class Solution
{
public:
    int bestClosingTime(const string customers)
    {
        const int n = customers.size();
        vector<int> v(n + 1);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'N')
            {
                ++cnt;
            }
            v[i + 1] = cnt;
        }
        cnt = 0;
        int mn = v[n];
        int res = n - 1;
        for (int i = n; i > -1; i--)
        {
            if (customers[i] == 'Y')
            {
                cnt++;
            }
            // cout <<"NORM " << i << " " << v[i] << endl;

            if ((v[i] + cnt) <= mn)
            {
                //   cout <<"CASE " << i << " " << v[i] << endl;
                mn = v[i] + cnt;
                res = i;
            }
        }
        return res;
    }
};