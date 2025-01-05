class Solution
{
public:
    long long calculateScore(string s)
    {
        map<char, char> charMirror = {
            {'a', 'z'},
            {'b', 'y'},
            {'c', 'x'},
            {'d', 'w'},
            {'e', 'v'},
            {'f', 'u'},
            {'g', 't'},
            {'h', 's'},
            {'i', 'r'},
            {'j', 'q'},
            {'k', 'p'},
            {'l', 'o'},
            {'m', 'n'},
            {'n', 'm'},
            {'o', 'l'},
            {'p', 'k'},
            {'q', 'j'},
            {'r', 'i'},
            {'s', 'h'},
            {'t', 'g'},
            {'u', 'f'},
            {'v', 'e'},
            {'w', 'd'},
            {'x', 'c'},
            {'y', 'b'},
            {'z', 'a'}};
        map<char, deque<int>> everyInd = {
            {'a', {}},
            {'b', {}},
            {'c', {}},
            {'d', {}},
            {'e', {}},
            {'f', {}},
            {'g', {}},
            {'h', {}},
            {'i', {}},
            {'j', {}},
            {'k', {}},
            {'l', {}},
            {'m', {}},
            {'n', {}},
            {'o', {}},
            {'p', {}},
            {'q', {}},
            {'r', {}},
            {'s', {}},
            {'t', {}},
            {'u', {}},
            {'v', {}},
            {'w', {}},
            {'x', {}},
            {'y', {}},
            {'z', {}}};
        ;
        long long score = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char current = s[i];
            if (!everyInd[charMirror[current]].size())
            {
                everyInd[s[i]].push_back(i);
            }
            else
            {
                int foundI = everyInd[charMirror[current]].back();
                score += i - foundI;
                everyInd[charMirror[current]].pop_back();
            }
        }
        return score;
    }
};
