class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string tempNonRepeat = "";
        int longestNonRepeatLength = 0;
        for (auto c : s)
        {
            int foundIndex = tempNonRepeat.find(c);
            if (foundIndex == -1)
            {
                tempNonRepeat += c;
                // cout << tempNonRepeat << endl;
                if (tempNonRepeat.length() > longestNonRepeatLength)
                {
                    longestNonRepeatLength = tempNonRepeat.length();
                }
            }
            else
            {
                tempNonRepeat = tempNonRepeat.substr(foundIndex + 1);
                tempNonRepeat += c;
                // cout << "FOUND " << c << " " << tempNonRepeat << endl;
            }
        }
        return longestNonRepeatLength;
    }
};