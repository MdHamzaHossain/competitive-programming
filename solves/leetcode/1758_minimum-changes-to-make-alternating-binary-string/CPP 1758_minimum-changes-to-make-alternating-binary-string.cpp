class Solution
{
public:
    int minOperations(const string s)
    {
        const int n = s.size();
        char prev = '2';
        int c1 = 0;
        cout << s << endl;
        for (int i = 0; i < n; i++)
        {
            char e = s[i];
            if (e == prev)
            {
                c1++;
                e = !(e - '0') + '0';
            }
            prev = e;
        }
        int c2 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            char e = s[i];
            if (e == prev)
            {
                c2++;
                e = !(e - '0') + '0';
            }
            prev = e;
        }
        cout << s << endl;
        return min(c1, c2);
    }
};