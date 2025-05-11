class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int odds = 0;
        for (auto e : arr)
        {
            if (e % 2 == 0)
                odds = 0;
            else
                odds++;
            if (odds == 3)
                break;
        }
        return odds == 3;
    }
};