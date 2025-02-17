class Solution
{
public:
    int dfs(int *count)
    {
        int result = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {
                result++;
                count[i]--;
                result += dfs(count);
                count[i]++;
            }
        }
        return result;
    };

    int numTilePossibilities(string tiles)
    {
        int count[26] = {};

        for (char tile : tiles)
        {
            count[tile - 'A']++;
        }
        return dfs(count);
    }
};
