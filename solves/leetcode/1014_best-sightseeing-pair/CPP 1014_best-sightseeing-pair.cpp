class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int maximLeft = 0;
        int maximRight = 0;
        for (int i = 0; i < values.size(); i++)
        {
            maximRight = max(maximRight, maximLeft + values[i] - i);

            maximLeft = max(maximLeft, values[i] + i);
        }

        return maximRight;
    }
};