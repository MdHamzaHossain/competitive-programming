class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int counter[] = {0, 0};
        for (auto num : nums)
        {
            if (num == 0)
                continue;
            counter[num > 0]++;
        }
        return max(counter[0], counter[1]);
    }
};