class Solution
{
public:
    string getHappyString(int n, int k)
    {
        unordered_map<char, string> el;
        el['a'] = "bc";
        el['b'] = "ac";
        el['c'] = "ab";
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");
        while (q.front().length() != n)
        {
            const string u = q.front();
            q.pop();
            for (const char nextLetter : el.at(u.back()))
                q.push(u + nextLetter);
        }

        if (q.size() < k)
            return "";

        for (int i = 0; i < k - 1; ++i)
            q.pop();
        return q.front();
    }
};