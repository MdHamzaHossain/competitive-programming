class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        int t = 1;

        while (ans.size() < n)
        {
            ans.push_back(t);
            if (t * 10 <= n)
                t *= 10;
            else
            {
                while (t % 10 == 9 || t == n)
                    t /= 10;
                t++;
            }
        }

        return ans;
    }
};