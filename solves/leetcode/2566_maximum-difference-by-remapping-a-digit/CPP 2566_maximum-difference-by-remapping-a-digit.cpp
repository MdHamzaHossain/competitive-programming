
class Solution
{
public:
    int minMaxDifference(int num)
    {
        string s1 = to_string(num);
        string mxS = s1;
        char s1F = s1[0];
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == s1F)
                s1[i] = '0';
        }
        int num2 = stoi(s1);

        for (int i = 0; i < mxS.size(); ++i)
        {
            if (mxS[i] != '9')
            {
                char curr = mxS[i];
                for (int j = i; j < mxS.size(); ++j)
                    if (mxS[j] == curr)
                        mxS[j] = '9';
                return stoi(mxS) - num2;
            }
        }
        return num - num2;
    }
};
