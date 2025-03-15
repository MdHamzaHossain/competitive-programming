class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {

        unordered_set<int> uniques(cbegin(nums), cend(nums));
        vector<int> sortedClone(cbegin(uniques), cend(uniques));
        sort(begin(sortedClone), end(sortedClone));
        int l = 0, r = size(sortedClone) - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0; i < (nums.size()); ++i)
            {
                if (nums[i] <= sortedClone[mid])
                {
                    ++cnt;
                    ++i;
                }
            }
            if (cnt >= k)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return sortedClone[l];
    }
};