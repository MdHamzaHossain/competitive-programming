class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> res;
        // BUT it tracks the max on one end lmao
        map<char, int> minTrack = {
            {'a', 0},
            {'b', 0},
            {'c', 0},
            {'d', 0},
            {'e', 0},
            {'f', 0},
            {'g', 0},
            {'h', 0},
            {'i', 0},
            {'j', 0},
            {'k', 0},
            {'l', 0},
            {'m', 0},
            {'n', 0},
            {'o', 0},
            {'p', 0},
            {'q', 0},
            {'r', 0},
            {'s', 0},
            {'t', 0},
            {'u', 0},
            {'v', 0},
            {'w', 0},
            {'x', 0},
            {'y', 0},
            {'z', 0}};
        unordered_set<char> exists;
        for (int i = 0; i < words2.size(); i++)
        {
            string word = words2[i];
            map<char, int> charCountTrack;
            for (char c : word)
            {
                exists.insert(c);
                if (!charCountTrack[c])
                    charCountTrack[c] = 1;
                else
                    charCountTrack[c]++;
                minTrack[c] = max(minTrack[c], charCountTrack[c]);
            }
        }
        for (int i = 0; i < words1.size(); i++)
        {
            string word = words1[i];
            map<char, int> charCountTrack;
            unordered_set<char> uniques;
            for (char c : word)
            {
                uniques.insert(c);
                if (!charCountTrack[c])
                    charCountTrack[c] = 1;
                else
                    charCountTrack[c]++;
            }
            int valid = 1;
            for (auto itr = exists.begin(); itr != exists.end(); itr++)
            {
                // cout << word << " c " << *itr << " min " << minTrack[*itr] << " is " << charCountTrack[*itr] << endl;
                if (minTrack[*itr] > charCountTrack[*itr])
                {
                    valid = 0;
                    break;
                }
            }
            if (valid)
                res.push_back(word);
        }
        return res;
    }
};