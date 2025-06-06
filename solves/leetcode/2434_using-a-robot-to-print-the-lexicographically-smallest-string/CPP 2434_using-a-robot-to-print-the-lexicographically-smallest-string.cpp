class Solution
{
public:
    string robotWithString(string s)
    {
        int charMapper[26] = {0};

        for (char ch : s)
            charMapper[ch - 'a']++;

        char minChar = 'a';
        string stack;
        string answer;

        for (char ch : s)
        {

            charMapper[ch - 'a']--;

            while (minChar < 'z' && charMapper[minChar - 'a'] == 0)
                minChar++;

            stack.push_back(ch);

            while (!stack.empty() && stack.back() <= minChar)
            {
                answer.push_back(stack.back());
                stack.pop_back();
            }
        }

        return answer;
    }
};