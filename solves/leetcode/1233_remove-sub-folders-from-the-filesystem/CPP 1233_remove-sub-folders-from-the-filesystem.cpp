class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folders)
    {
        sort(folders.begin(), folders.end());
        vector<string> res;
        res.push_back(folders[0]);
        for (int i = 1; i < folders.size(); ++i)
            if (res.back().size() >= folders[i].size() ||
                !(res.back() == folders[i].substr(0, res.back().size()) && folders[i][res.back().size()] == '/'))
                res.emplace_back(folders[i]);

        return res;
    }
};