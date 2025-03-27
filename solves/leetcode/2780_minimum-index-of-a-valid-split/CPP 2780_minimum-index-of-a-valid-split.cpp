class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int x = 0, count = 0;
        unordered_map<int, int> tracker;
        for (auto e : nums)
        {
            ++tracker[e];
            if (tracker[e] > count)
            {
                count = tracker[e];
                x = e;
            }
        }
        int cnt2 = 0;
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (nums[i - 1] == x)
            {
                ++cnt2;
                if (cnt2 * 2 > i && (count - cnt2) * 2 > nums.size() - i)
                    return i - 1;
            }
        }
        return -1;
    }
};