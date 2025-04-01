class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<long long> temp(questions.size() + 1);

        for (int i = questions.size() - 1; i >= 0; --i)
            temp[i] = max(questions[i][0] + (i + questions[i][1] + 1 < questions.size() ? temp[i + questions[i][1] + 1] : 0), temp[i + 1]);

        return temp[0];
    }
};