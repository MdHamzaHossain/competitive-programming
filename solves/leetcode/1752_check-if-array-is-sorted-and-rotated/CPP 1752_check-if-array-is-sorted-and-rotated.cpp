class Solution
{
public:
    bool check(vector<int> &nums)
    {
        bool valid = true;
        int unsorted = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[(i + 1) % nums.size()])
            {
                unsorted++;
                if (unsorted > 1)
                {
                    valid = false;
                    break;
                }
            }
        }
        return valid;
    }
};