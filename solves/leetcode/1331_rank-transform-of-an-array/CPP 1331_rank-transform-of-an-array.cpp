class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> clone = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int count = 1;
        for (int i = 0; i < arr.size(); i++)
            if (!mp[arr[i]])
                mp[arr[i]] = count++;
        for (int i = 0; i < arr.size(); i++)
            clone[i] = mp[clone[i]];
        return clone;
    }
};