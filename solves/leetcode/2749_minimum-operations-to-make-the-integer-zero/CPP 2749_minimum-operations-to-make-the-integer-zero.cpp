// TODO
class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {

        for (long i = 0; i <= 60; ++i)
        {
            const long target = num1 - i * num2;
            if (__builtin_popcountl(target) <= i && i <= target)
                return i;
        }

        return -1;
    }
};