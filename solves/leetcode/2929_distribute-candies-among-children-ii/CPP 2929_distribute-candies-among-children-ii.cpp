class Solution
{
public:
    long long distributeCandies(int candies, int limit)
    {
        auto helper = [](int number) -> long long
        {
            return static_cast<long long>(number) * (number - 1) / 2;
        };

        if (candies > 3 * limit)
            return 0;

        long long res = helper(candies + 2);

        if (candies > limit)
            res -= 3 * helper(candies - limit + 1);

        if (candies - 2 >= 2 * limit)
            res += 3 * helper(candies - 2 * limit);

        return res;
    }
};