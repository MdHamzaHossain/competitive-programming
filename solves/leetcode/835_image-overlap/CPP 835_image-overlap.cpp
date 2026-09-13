// TODO
class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();

        map<pair<int, int>, int> translationCount;
        int maxOverlap = 0;

        for (int row1 = 0; row1 < n; ++row1)
        {
            for (int col1 = 0; col1 < n; ++col1)
            {
                if (img1[row1][col1] == 1)
                {

                    for (int row2 = 0; row2 < n; ++row2)
                    {
                        for (int col2 = 0; col2 < n; ++col2)
                        {
                            if (img2[row2][col2] == 1)
                            {

                                int deltaRow = row1 - row2;
                                int deltaCol = col1 - col2;

                                translationCount[{deltaRow, deltaCol}]++;
                                maxOverlap = max(maxOverlap, translationCount[{deltaRow, deltaCol}]);
                            }
                        }
                    }
                }
            }
        }

        return maxOverlap;
    }
};
