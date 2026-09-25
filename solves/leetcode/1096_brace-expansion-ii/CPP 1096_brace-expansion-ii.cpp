// TODO
class Solution
{
public:
    vector<string> braceExpansionII(string expression)
    {
        expandExpression(expression);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    set<string> resultSet;

    void expandExpression(string expression)
    {

        int closeBracePos = expression.find_first_of('}');

        if (closeBracePos == string::npos)
        {
            resultSet.insert(expression);
            return;
        }

        int openBracePos = expression.rfind('{', closeBracePos);
        string prefix = expression.substr(0, openBracePos);
        string suffix = expression.substr(closeBracePos + 1);
        string bracedContent = expression.substr(openBracePos + 1, closeBracePos - openBracePos - 1);
        stringstream optionStream(bracedContent);
        string option;
        while (getline(optionStream, option, ','))
            expandExpression(prefix + option + suffix);
    }
};
