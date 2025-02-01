class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        bool isSpecial = true;
        int tempCount = nums[0] % 2;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] % 2 == tempCount)
            {
                isSpecial = false;
                break;
            }
            tempCount = !tempCount;
        }
        return isSpecial;
    }
};