// TODO
class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {

        if (num * 9 < sum)
        {
            return "";
        }

        int nineCount = sum / 9;
        int remainder = sum % 9;

        string ans(nineCount, '9');

        if (remainder > 0)
        {
            ans += char('0' + remainder);
        }

        ans += string(num - ans.size(), '0');

        return ans;
    }
};
