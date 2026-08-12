// TODO
class Solution
{
public:
    int maxSubarrayLength(vector<int> &arr, int K)
    {

        int res = 0;

        unordered_map<int, int> mp;

        int l = 0;
        for (int r = 0; r < arr.size(); r++)
        {

            mp[arr[r]]++;

            while (mp[arr[r]] > K)
            {
                mp[arr[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};