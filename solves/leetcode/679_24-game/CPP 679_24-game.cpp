// TODO
class Solution
{
public:
    bool judgePoint24(vector<int> &nums)
    {
        vector<double> numList(nums.begin(), nums.end());
        return dfs(numList);
    }

private:
    bool dfs(vector<double> &numList)
    {
        if (numList.empty())
        {
            return false;
        }
        if (numList.size() == 1)
        {
            return abs(numList[0] - 24.0) < 1e-6;
        }

        for (int i = 0; i < numList.size(); ++i)
        {
            for (int j = i + 1; j < numList.size(); ++j)
            {

                for (int operation = 0; operation < 6; ++operation)
                {
                    vector<double> nextList = getNextList(numList, i, j, operation);
                    if (!nextList.empty() && dfs(nextList))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    vector<double> getNextList(vector<double> &numList, int firstIndex, int secondIndex, int operation)
    {
        vector<double> nextNumList;

        for (int k = 0; k < numList.size(); ++k)
        {
            if (k != firstIndex && k != secondIndex)
            {
                nextNumList.push_back(numList[k]);
            }
        }

        double firstNumber = numList[firstIndex];
        double secondNumber = numList[secondIndex];

        switch (operation)
        {
        case 0:
            nextNumList.push_back(firstNumber + secondNumber);
            break;
        case 1:
            nextNumList.push_back(firstNumber - secondNumber);
            break;
        case 2:
            nextNumList.push_back(secondNumber - firstNumber);
            break;
        case 3:
            nextNumList.push_back(firstNumber * secondNumber);
            break;
        case 4:
            if (abs(secondNumber) < 1e-6)
            {
                return {};
            }
            nextNumList.push_back(firstNumber / secondNumber);
            break;
        case 5:
            if (abs(firstNumber) < 1e-6)
            {
                return {};
            }
            nextNumList.push_back(secondNumber / firstNumber);
            break;
        }

        return nextNumList;
    }
};