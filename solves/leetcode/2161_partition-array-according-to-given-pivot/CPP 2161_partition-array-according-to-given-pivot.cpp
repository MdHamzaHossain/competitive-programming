class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> res;

        for (auto e : nums)
            if (e < pivot)
                res.push_back(e);

        for (auto e : nums)
            if (e == pivot)
                res.push_back(e);

        for (int e : nums)
            if (e > pivot)
                res.push_back(e);

        return res;
    }
};