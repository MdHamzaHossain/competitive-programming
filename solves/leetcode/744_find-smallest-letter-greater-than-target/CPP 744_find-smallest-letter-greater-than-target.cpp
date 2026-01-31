class Solution
{
public:
    char nextGreatestLetter(const vector<char> &letters, const char target)
    {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return (it == letters.end() ? letters[0] : *it);
    }
};