class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;

        for (int i = digits.size() - 1; i > -1; i--)
        {
            int jimCarry = digits[i] + carry;
            if (jimCarry > 9)
            {
                digits[i] = (jimCarry) % 10;
                carry = (jimCarry / 10);
            }
            else
            {
                digits[i] += carry;
                carry = 0;
            }
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};