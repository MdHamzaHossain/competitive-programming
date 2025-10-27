// TODO
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int ans = 0;
        int prev = 0;
        for (const auto &row : bank)
        {
            int curr = count(row.begin(), row.end(), '1');
            if (curr > 0)
            {
                ans += prev * curr;
                prev = curr;
            }
        }

        return ans;
    }
};
