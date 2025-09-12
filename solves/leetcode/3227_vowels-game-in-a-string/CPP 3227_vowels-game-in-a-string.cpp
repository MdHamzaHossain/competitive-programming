// TODO
class Solution
{
public:
    bool isVowel(char c)
    {
        static constexpr string_view kVowels = "aeiou";
        return kVowels.find(c) != string_view::npos;
    }
    bool doesAliceWin(string s)
    {
        return ranges::any_of(s, [this](char c)
                              { return isVowel(c); });
    }
};