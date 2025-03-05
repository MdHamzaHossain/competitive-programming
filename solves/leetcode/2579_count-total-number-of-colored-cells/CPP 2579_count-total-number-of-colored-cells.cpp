typedef long long ll;
class Solution
{
public:
    long long coloredCells(int n)
    {

        return (ll)n * (ll)n + ((ll)n - 1) * ((ll)n - 1);
    }
};