class Solution
{
public:
    int getCommon(const vector<int> &nums1, const vector<int> &nums2)
    {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        int l = 0;
        int r = 0;
        while (l < n1 && r < n2)
        {
            const int c = nums1[l] - nums2[r];
            if (c == 0)
                return nums1[l];
            if (c > 0)
                r++;
            else
                l++;
        }
        return -1;
    }
};