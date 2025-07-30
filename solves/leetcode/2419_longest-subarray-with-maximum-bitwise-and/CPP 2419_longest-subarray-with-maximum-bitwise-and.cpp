class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());
        int longestSubarrayLength = 0, currentSubarrayLength = 0;
        for (int value : nums)
        {
            if (value == mx)
            {
                ++currentSubarrayLength;
                longestSubarrayLength = max(longestSubarrayLength, currentSubarrayLength);
            }
            else
                currentSubarrayLength = 0;
        }
        return longestSubarrayLength;
    }
};