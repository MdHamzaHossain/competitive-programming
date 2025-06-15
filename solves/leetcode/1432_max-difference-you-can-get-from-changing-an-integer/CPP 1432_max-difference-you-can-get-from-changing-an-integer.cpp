class Solution
{
public:
    void replaceAll(string &s, char from, char to)
    {
        for (char &c : s)
            if (c == from)
                c = to;
    }

    int maxDiff(int num)
    {

        string highestNumStr = to_string(num);
        string lowestNumStr = highestNumStr;

        for (int i = 0; i < highestNumStr.size(); ++i)
        {
            if (highestNumStr[i] != '9')
            {
                replaceAll(highestNumStr, highestNumStr[i], '9');
                break;
            }
        }

        if (lowestNumStr[0] != '1')
            replaceAll(lowestNumStr, lowestNumStr[0], '1');
        else
        {

            for (int i = 1; i < lowestNumStr.size(); ++i)
            {
                if (lowestNumStr[i] != '0' && lowestNumStr[i] != '1')
                {
                    replaceAll(lowestNumStr, lowestNumStr[i], '0');
                    break;
                }
            }
        }

        return stoi(highestNumStr) - stoi(lowestNumStr);
    }
};