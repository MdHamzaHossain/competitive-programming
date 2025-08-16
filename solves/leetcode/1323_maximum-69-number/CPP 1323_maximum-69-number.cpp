// Did this on phone lmao
class Solution
{
public:
    int maximum69Number(int num)
    {
        string s1 = to_string((num));
        if (s1.find('6') != string::npos)
        {
            s1[(int)(s1.find('6'))] = '9';
        }
        return stoi(s1);
    }
};