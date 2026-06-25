// TODO
class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int ans = 0;

        for (int left = 0; left < n; ++left)
        {

            unordered_map<int, int> count;

            for (int right = left; right < n; ++right)
            {

                int length = right - left + 1;

                count[nums[right]]++;
                if (count[target] > length / 2)
                {
                    ++ans;
                }
            }
        }

        return ans;
    }
};
