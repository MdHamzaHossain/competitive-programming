class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        unordered_set<int> uniques;
        int mini = nums.at(0);
        for (auto e : nums)
        {
            mini = min(mini, e);
            uniques.insert(e);
        }
        if (mini == k)
            return uniques.size() - 1;
        else if (mini < k)
            return -1;
        else
            return uniques.size();
    }
};