class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> ans;
        vector<int> track(nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        int maxSize = 0;
        int index = -1;

        ranges::sort(nums);

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
                if (nums[i] % nums[j] == 0 && track[i] < track[j] + 1)
                {
                    track[i] = track[j] + 1;
                    prev[i] = j;
                }
            if (maxSize < track[i])
            {
                maxSize = track[i];
                index = i;
            }
        }

        while (index != -1)
        {
            ans.push_back(nums[index]);
            index = prev[index];
        }

        return ans;
    }
};