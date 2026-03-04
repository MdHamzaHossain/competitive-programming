
class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        const int r = mat.size();
        const int c = mat[0].size();
        vector<int> rowOnes(r, 0);
        vector<int> colOnes(c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 1)
                {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] && rowOnes[i] == 1 && colOnes[j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};