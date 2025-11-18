class Solution
{
public:
    bool isOneBitCharacter(const vector<int> &bits)
    {
        const int n = bits.size();
        for (int i = 0; i < n; i++)
        {

            if (i == n - 1)
                return true;
            if (bits[i] == 1)
                i++;
        }
        return false;
    }
};