// TODO
class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.size();

        bool isSorted = true;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] < s[i - 1])
            {
                isSorted = false;
                break;
            }
        }

        if (isSorted)
        {
            return 0;
        }

        if (n == 2)
        {
            return -1;
        }

        char minChar = *min_element(s.begin(), s.end());
        char maxChar = *max_element(s.begin(), s.end());

        if (s[0] == minChar || s[n - 1] == maxChar)
        {
            return 1;
        }

        for (int i = 1; i < n - 1; ++i)
        {
            if (s[i] == minChar || s[i] == maxChar)
            {
                return 2;
            }
        }

        return 3;
    }
};
