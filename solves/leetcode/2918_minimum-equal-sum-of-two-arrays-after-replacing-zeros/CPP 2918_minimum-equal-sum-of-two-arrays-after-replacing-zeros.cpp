class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long s1 = 0;
        long long s2 = 0;
        bool weTheZeroes = false;

        for (int num : nums1)
        {
            if (num == 0)
                weTheZeroes = true;
            s1 += max(num, 1);
        }

        for (int num : nums2)
            s2 += max(num, 1);

        if (s1 > s2)
            return minSum(nums2, nums1);

        if (s1 == s2)
            return s1;

        return weTheZeroes ? s2 : -1;
    }
};