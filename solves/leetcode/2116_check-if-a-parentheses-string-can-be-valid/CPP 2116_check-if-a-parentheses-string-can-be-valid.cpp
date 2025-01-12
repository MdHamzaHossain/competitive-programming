class Solution
{
public:
    bool canBeValid(string s, string locked)
    {

        int closing = 0;
        int opening = 0;
        int unlocked = 0;
        bool valid = true;
        if (s.size() % 2 == 1)
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            // If it is unlocked, it doesn't really matter what it is
            if (locked[i] == '0')
                unlocked++;
            else if (s[i] == '(')
                opening++;
            else
                closing++;
            // the amount of items that need changing is bigger than the amount of items that can be changed. not possible..
            if (unlocked < (closing - opening))
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            // hit it from the back
            opening = 0;
            unlocked = 0;
            closing = 0;

            for (int i = s.size() - 1; i > -1; i--)
            {
                if (locked[i] == '0')
                    unlocked++;
                // Logic inversed from the back, now up is doooown left is right
                else if (s[i] == ')')
                    opening++;
                else
                    closing++;
                // the amount of items that need changing is bigger than the amount of items that can be changed. not possible..
                if (unlocked < (closing - opening))
                {
                    valid = false;
                    break;
                }
            }
        }
        return valid;
    }
};