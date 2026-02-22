// TODO
class Solution
{
public:
    int binaryGap(int n)
    {
        int maxDistance = 0;

        int previousOnePosition = 100;
        int currentPosition = 0;

        while (n != 0)
        {

            if (n & 1)
            {

                maxDistance = max(maxDistance, currentPosition - previousOnePosition);

                previousOnePosition = currentPosition;
            }

            ++currentPosition;

            n >>= 1;
        }

        return maxDistance;
    }
};
