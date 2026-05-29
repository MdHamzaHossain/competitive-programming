class Solution
{
public:
    int minElement(vector<int> &nums)
    {
        int mn = 60;
        for (auto &e : nums)
        {
            string s = to_string(e);
            int sum = 0;
            for (auto c : s)
            {
                sum += c - '0';
            }
            mn = min(sum, mn);
        }
        return mn;
    }
};