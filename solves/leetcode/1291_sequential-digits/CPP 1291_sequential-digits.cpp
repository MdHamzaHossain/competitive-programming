// TODO
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> result;

        for (int startDigit = 1; startDigit < 9; ++startDigit)
        {
            int currentNumber = startDigit;
            for (int nextDigit = startDigit + 1; nextDigit < 10; ++nextDigit)
            {
                currentNumber = currentNumber * 10 + nextDigit;

                if (currentNumber >= low && currentNumber <= high)
                    result.push_back(currentNumber);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};