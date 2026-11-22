class Solution
{
public:
    bool checkString(string s)
    {
        bool foundB = 0;
        bool valid = 1;
        for (auto &c : s)
        {
            if (c == 'b')
                foundB = 1;
            if (c == 'a' && foundB)
                valid = 0;
        }
        return valid;
    }
};