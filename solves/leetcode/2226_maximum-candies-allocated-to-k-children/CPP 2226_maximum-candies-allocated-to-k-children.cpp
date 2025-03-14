class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long totalChildren)
    {
        int minC = 0, maxC = 1e7;

        while (minC < maxC)
        {
            int mid = (minC + maxC + 1) / 2;

            long long chils = 0;

            for (int currC : candies)
                chils += currC / mid;

            if (chils >= totalChildren)
                minC = mid;
            else
                maxC = mid - 1;
        }

        return minC;
    }
};