class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int whiteys = count(blocks.begin(), blocks.begin() + k, 'W');
        int mn = whiteys;
        for (int i = k; i < blocks.size(); ++i)
        {
            whiteys += blocks[i] == 'W';
            whiteys -= blocks[i - k] == 'W';
            mn = min(mn, whiteys);
        }

        return mn;
    }
};