class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;
        for (auto &e : nums)
        {
            int divSum = 1;
            int divCount = 2;
            for (int i = 2; i * i <= e; i++)
            {
                if (e % i == 0)
                {
                    divSum += i, divCount++;
                    // cout << "debbieg " << e << ' ' << i << endl;
                    if (i * i != e)
                    {
                        divSum += e / i, divCount++;
                    }
                }
            }
            divSum += e;
            if (divCount == 4)
                sum += divSum;
        }
        return sum;
    }
};