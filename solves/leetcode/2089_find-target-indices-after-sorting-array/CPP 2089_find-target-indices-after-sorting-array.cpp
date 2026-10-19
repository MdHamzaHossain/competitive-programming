class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, const int target)
    {
        vector<int> r;
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        auto ind = lower_bound(nums.begin(), nums.end(), target);
        while (ind != nums.end() && *ind == target)
        {
            cout << *ind << endl;
            r.push_back(ind - nums.begin());
            ind++;
        }
        return r;
    }
};