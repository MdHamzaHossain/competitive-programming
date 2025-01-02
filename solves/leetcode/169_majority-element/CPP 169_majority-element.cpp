class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int maj = nums.size() / 2;
        map<int, int> count;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count[nums[i]])
            {
                count[nums[i]]++;
                if (count[nums[i]] > maj)
                    return nums[i];
            }
            else
            {
                count[nums[i]] = 1;
            }
        }
        return 0;
    }
};