class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        const int n = s.size();
        int starting = goal.find(s[0]);
        if (starting == -1 || n != goal.size())
            return false;
        bool pos = true;
        while (starting != -1)
        {
            pos = true;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != goal[(starting + i) % n])
                {
                    pos = false;
                    break;
                }
            }
            if (pos)
                break;
            starting = goal.find(s[0], starting + 1);
        }
        return pos;
    }
};