class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int i;
        for (i = 0; i < strs.at(0).size(); i++)
        {
            char c = strs[0][i];
            bool match = true;
            for (int j = 0; j < strs.size(); j++)
            {

                if (i >= strs[j].size() || strs[j][i] != c)
                {
                    match = false;
                    break;
                }
            }
            if (!match)
                break;
        }
        return strs[0].substr(0, i);
    }
};