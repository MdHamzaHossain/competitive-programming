// TODO
class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> result;

        for (int number : nums)
        {
            vector<int> tempDigits;

            while (number > 0)
            {
                tempDigits.push_back(number % 10);
                number /= 10;
            }

            while (!tempDigits.empty())
            {
                result.push_back(tempDigits.back());
                tempDigits.pop_back();
            }
        }

        return result;
    }
};
