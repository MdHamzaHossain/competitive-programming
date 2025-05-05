class Solution
{
public:
    int numTilings(int n)
    {
        int MOD = 1e9 + 7;
        long dirs[4] = {1, 0, 0, 0};

        for (int i = 1; i <= n; ++i)
        {
            long newDir[4] = {0, 0, 0, 0};

            newDir[0] = (dirs[0] + dirs[1] + dirs[2] + dirs[3]) % MOD;
            newDir[1] = (dirs[2] + dirs[3]) % MOD;
            newDir[2] = (dirs[1] + dirs[3]) % MOD;
            newDir[3] = dirs[0];

            memcpy(dirs, newDir, sizeof(newDir));
        }

        return dirs[0];
    }
};