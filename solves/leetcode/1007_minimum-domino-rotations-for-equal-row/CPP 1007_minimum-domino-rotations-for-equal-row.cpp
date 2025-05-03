class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int ans = INT_MAX;
        int n = tops.size();

        unordered_map<int, int> traq;
        for (int i = 0; i < tops.size(); i++)
        {
            traq[tops[i]]++;
            traq[bottoms[i]] += bottoms[i] != tops[i];
        }

        for (int i = 1; i <= 6; i++)
        {
            if (traq[i] < n)
                continue;

            int cT = 0, cB = 0;
            for (int j = 0; j < n; j++)
            {
                cT += tops[j] != i;
                cB += bottoms[j] != i;
            }
            ans = min(ans, min(cT, cB));
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};