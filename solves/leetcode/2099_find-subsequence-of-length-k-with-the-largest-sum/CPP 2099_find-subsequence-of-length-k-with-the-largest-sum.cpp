// TODO
class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<int> res;
        vector<int> arr(nums);
        nth_element(arr.begin(), arr.end() - k, arr.end());
        const int threshold = arr[arr.size() - k];
        const int larger =
            ranges::count_if(nums, [&](int num)
                             { return num > threshold; });
        int equal = k - larger;

        for (const int num : nums)
            if (num > threshold)
            {
                res.push_back(num);
            }
            else if (num == threshold && equal)
            {
                res.push_back(num);
                --equal;
            }

        return res;
    }
};