class Solution
{
public:
    void addC(const vector<vector<int>> &currNum, vector<int> &count)
    {
        for (const vector<int> &idVal : currNum)
        {
            count[idVal[0]] += idVal[1];
        }
    }
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                    vector<vector<int>> &nums2)
    {
        vector<vector<int>> ans;
        vector<int> count(1000 + 1);

        addC(nums1, count);
        addC(nums2, count);

        for (int i = 1; i <= 1000; i++)
            if (count[i] > 0)
                ans.push_back({i, count[i]});

        return ans;
    }
};