
class Solution
{
public:
    int totalMoney(const int &n)
    {
        const int d = n / 7;
        const int r = n % 7;

        return (d * (56 + 7 * (d - 1) + r) + r * (d + r + 1)) / 2;
    }
};