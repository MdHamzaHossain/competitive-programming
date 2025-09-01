// TODO
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {

        priority_queue<tuple<double, int, int>> potentialQueue;

        for (const auto &cls : classes)
        {
            int passCount = cls[0], totalCount = cls[1];
            double potentialIncrease = static_cast<double>(passCount + 1) / (totalCount + 1) - static_cast<double>(passCount) / totalCount;
            potentialQueue.push({potentialIncrease, passCount, totalCount});
        }

        while (extraStudents--)
        {

            auto [potential, passCount, totalCount] = potentialQueue.top();
            potentialQueue.pop();

            passCount++;
            totalCount++;
            double potentialIncrease = static_cast<double>(passCount + 1) / (totalCount + 1) - static_cast<double>(passCount) / totalCount;
            potentialQueue.push({potentialIncrease, passCount, totalCount});
        }

        double totalRatio = 0;
        while (!potentialQueue.empty())
        {
            auto [_, passCount, totalCount] = potentialQueue.top();
            potentialQueue.pop();
            totalRatio += static_cast<double>(passCount) / totalCount;
        }

        return totalRatio / classes.size();
    }
};
