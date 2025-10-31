class Solution
{
public:
    vector<int> getSneakyNumbers(const vector<int> &nums)
    {
        const char n = nums.size();
        vector<bool> t(n, false);
        char res[2];
        char ind = 0;
        for (char i = 0; i < n; i++)
        {
            const char e = nums[i];
            if (t[e])
            {
                res[ind++] = e;
                if (ind == 2)
                    break;
            }
            else
                t[e] = true;
        }
        return {res[0], res[1]};
    }
};