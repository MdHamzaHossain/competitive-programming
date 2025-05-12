class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> digitCount = countDigits(digits);
        vector<int> evenNumbers;
        for (int num = 100; num < 1000; num += 2)
        {
            vector<int> numDigits = getDigits(num);
            vector<int> numDigitCount = countDigits(numDigits);
            if (canFormNumber(digitCount, numDigitCount))
                evenNumbers.push_back(num);
        }
        return evenNumbers;
    }
    vector<int> countDigits(vector<int> &nums)
    {
        vector<int> counter(10, 0);
        for (int num : nums)
            counter[num]++;
        return counter;
    }

    bool canFormNumber(vector<int> &availableDigits, vector<int> &neededDigits)
    {
        for (int i = 0; i < 10; ++i)
            if (availableDigits[i] < neededDigits[i])
                return false;
        return true;
    }

    vector<int> getDigits(int num)
    {
        vector<int> digits;
        string s = to_string(num);
        for (auto c : s)
            digits.push_back(c - '0');
        return digits;
    }
};