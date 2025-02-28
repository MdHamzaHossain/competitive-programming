class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int s1 = str1.size();
        int s2 = str2.size();

        vector<vector<int>> tracker(s1 + 1, vector<int>(s2 + 1, 0));

        for (int i = 1; i <= s1; i++)
        {
            for (int j = 1; j <= s2; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    tracker[i][j] = tracker[i - 1][j - 1] + 1;
                }
                else
                {
                    tracker[i][j] = max(tracker[i - 1][j], tracker[i][j - 1]);
                }
            }
        }

        string ans;
        int i = s1, j = s2;
        while (i > 0 || j > 0)
        {
            if (i == 0)
            {
                j--;
                ans += str2[j];
            }
            else if (j == 0)
            {
                i--;
                ans += str1[i];
            }
            else
            {
                if (tracker[i][j] == tracker[i - 1][j])
                {
                    i--;

                    ans += str1[i];
                }
                else if (tracker[i][j] == tracker[i][j - 1])
                {
                    j--;
                    ans += str2[j];
                }
                else
                {
                    i--;
                    ans += str1[i];
                    j--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};