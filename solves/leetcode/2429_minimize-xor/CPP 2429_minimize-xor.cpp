class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int amountOfBitsInNum2 = __builtin_popcount(num2);
        int amountOfBitsInNum1 = __builtin_popcount(num1);

        while (amountOfBitsInNum1 > amountOfBitsInNum2)
        {
            // Go one bit at a time
            num1 = num1 & (num1 - 1);
            amountOfBitsInNum1--;
        }
        while (amountOfBitsInNum1 < amountOfBitsInNum2)
        {

            num1 = num1 | (num1 + 1);
            amountOfBitsInNum1++;
        }
        return num1;
    }
};