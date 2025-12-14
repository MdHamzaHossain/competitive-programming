class Solution
{
public:
    int numberOfWays(const string &corridor)
    {
        const long long MOOD = 1e9 + 7;
        const int n = corridor.size();
        vector<int> r(n);
        vector<int> l(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
                ++cnt;
            l[i] = cnt;
        }
        cnt = 0;
        for (int i = n - 1; i > -1; i--)
        {
            r[i] = cnt;
            if (corridor[i] == 'S')
                cnt++;
        }
        long long ans = 0;
        int con = 0;
        for (int i = 0; i < n; i++)
        {
            //  cout << "DEBUG " << i << " " << corridor[i] << " " << l[i] << " " << r[i] << endl;
            if (r[i] % 2 == 0 && l[i] && l[i] % 2 == 0)
            {
                con++;
                if (r[i] == 0)
                    break;
            }

            else if (con)
            {
                //  cout << con << endl;
                ans = (ans ? ans : 1) * con % MOOD;
                con = 0;
            }
        }
        ans = (ans ? ans : 1) * con % MOOD;
        return ans;
    }
};