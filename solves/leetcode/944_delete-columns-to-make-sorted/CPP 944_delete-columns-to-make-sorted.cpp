class Solution
{
public:
    int minDeletionSize(const vector<string> &strs)
    {
        const uint16_t n = strs.size();
        const uint16_t ln = strs[0].size();
        uint16_t cnt = 0;

        for (uint16_t i = 0; i < ln; i++)
        {
            for (uint16_t j = 1; j < n; j++)
            {
                if (strs[j - 1][i] > strs[j][i])
                {
                    ++cnt;
                    break;
                }
            }
        }
        return cnt;
    }
};