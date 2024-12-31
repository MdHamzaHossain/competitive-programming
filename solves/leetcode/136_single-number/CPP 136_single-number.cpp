class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = 0;
        map<int, int> count;
        vector<int> uniques;
        for (int i = 0; i < nums.size(); i++)
        {
            int t = nums[i];

            if (!count[t])
            {
                count[t] = 1;
                uniques.push_back(t);
            }
            else
                count[t]++;
        }
        for (int a : nums)
        {
            if (count[a] == 1)
            {
                n = a;
                break;
            };
        }
        return n;
    }
};