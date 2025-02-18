class Solution
{
public:
    string smallestNumber(string pattern)
    {
        string res;
        deque<char> stack{{'1'}};

        for (const char c : pattern)
        {
            char mx = stack.back();
            if (c == 'I')
                while (!stack.empty())
                {
                    mx = max(mx, stack.back());
                    res += stack.back(), stack.pop_back();
                }
            stack.push_back(mx + 1);
        }

        while (!stack.empty())
            res += stack.back(), stack.pop_back();

        return res;
    }
};