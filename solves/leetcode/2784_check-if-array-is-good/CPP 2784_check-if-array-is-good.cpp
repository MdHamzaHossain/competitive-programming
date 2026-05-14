class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        if (*(nums.end() - 1) != n - 1)
        {
            return false;
        }
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] != i)
                return false;
        }
        return true;
    }
};
//* non-sort
class Solution
{
public:
    bool isGood(const vector<int> &nums)
    {
        const int n = nums.size();
        bitset<201> bs;
        for (auto &e : nums)
        {
            if (e > n - 1)
                return false;
            if (e == n - 1 && bs[e] == 1)
                bs[0] = 1;

            bs[e] = 1;
        }
        return bs.count() == n;
    }
};