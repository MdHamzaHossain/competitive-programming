class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        vector<int> rowCounter(mat.size());
        vector<int> colCounter(mat[0].size());

        map<int, int> rowTracker;
        map<int, int> colTracker;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                rowTracker[mat[i][j]] = i;
                colTracker[mat[i][j]] = j;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            colCounter[colTracker[arr[i]]]++;
            rowCounter[rowTracker[arr[i]]]++;

            if (colCounter[colTracker[arr[i]]] == mat.size() || rowCounter[rowTracker[arr[i]]] == mat[0].size())
                return i;
        }
        return 0;
    }
};