class Solution
{
public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        // int max1=0; int max2=0;
        // int step1=0; int step2=0;
        //  for each column
        vector<int> maxTracker = vector<int>(grid.at(0).size(), 0);
        int step2 = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.at(0).size(); j++)
            {
                int max1 = maxTracker.at(j);
                int t1 = grid.at(i)[j];
                if (i == 0)
                {
                    maxTracker.at(j) = t1;
                    continue;
                }
                if (max1 >= t1)
                {
                    while (t1 <= max1)
                    {
                        t1++;
                        step2++;
                    }
                }
                if (t1 > max1)
                    maxTracker.at(j) = t1;
            }
        }
        return step2;
    }
};