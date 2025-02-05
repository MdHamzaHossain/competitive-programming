class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int diff = 0;
        int firstInd = -1;
        bool valid = true;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                diff++;

                if (firstInd == -1)
                {
                    firstInd = i;
                    continue;
                }
                if (diff == 2 && (s2[firstInd] != s1[i] || s1[firstInd] != s2[i]))
                {
                    valid = false;
                    break;
                }
                if (diff == 3)
                {
                    valid = false;
                    break;
                }
            }
        }
        if (diff == 1)
            valid = false;

        return valid;
    }
};