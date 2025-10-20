class Solution
{
public:
    int finalValueAfterOperations(const vector<string> &operations)
    {
        char t = 0;
        const unsigned char n = operations.size();
        for (unsigned char i = 0; i < n; i++)
        {
            const char e = (operations[i][0] == 'X') ? operations[i][1] : operations[i][0];
            t += ((e) == '+') == 0 ? -1 : 1;
        }
        return t;
    }
};