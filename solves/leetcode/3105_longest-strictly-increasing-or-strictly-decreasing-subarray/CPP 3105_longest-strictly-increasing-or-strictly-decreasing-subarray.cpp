class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int mx = 0;
        int amount = 0;
        if (nums.size() == 1)
            return 1;
        int conditionApply = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int signum = (nums[i] > nums[i + 1]) - (nums[i] < nums[i + 1]);
            // cout << "DEBUG sig " << signum << " cond " << conditionApply << " amount " << amount << " t " << nums[i] << " t+1 " << nums[i+1] << endl;;
            if (signum == 0)
            {
                // mx = max(amount, mx);
                amount = 1;
                conditionApply = 0;
            }
            else
            {
                if (signum == conditionApply)
                    amount++;
                else
                {
                    conditionApply = signum;
                    // mx = max(amount, mx);
                    amount = 2;
                }
            }
            mx = max(amount, mx);
        }
        return mx;
    }
};