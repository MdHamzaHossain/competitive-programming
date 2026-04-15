class Solution
{
public:
    int closestTarget(vector<string> &words, string target, int startIndex)
    {
        const int n = words.size();
        int res = 200;
        for (int i = 0; i < n; i++)
        {
            if (words[i] == target)
            {
                // cout << "DEB " << startIndex << " " << i  << "bruh " << abs(startIndex - i) << ' ' <<(n- startIndex + i)  << ' ' << ' '<< endl;
                res = min(res, min(abs(startIndex - i), min(n - startIndex + i, n - i + startIndex)));
            }
        }
        if (res == 200)
            res = -1;
        return res;
    }
};