// TODO
// class Solution
// {
// public:
//     int countBinarySubstrings(string s)
//     {
//         int ones = 0;
//         int zeroes = 0;
//         int cnt = 0;
//         for (auto &c : s)
//         {
//             if (c == '0')
//                 zeroes += ;
//             else
//                 ones++;
//             if (ones == zeroes)
//                 cnt++;
//         }
//     }
// };
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int currentIndex = 0;
        int stringLength = s.size();
        vector<int> groupSizes;

        while (currentIndex < stringLength)
        {
            int groupCount = 1;
            while (currentIndex + 1 < stringLength && s[currentIndex + 1] == s[currentIndex])
            {
                ++groupCount;
                ++currentIndex;
            }
            groupSizes.push_back(groupCount);
            ++currentIndex;
        }

        int result = 0;

        for (int i = 1; i < groupSizes.size(); ++i)
        {
            result += min(groupSizes[i - 1], groupSizes[i]);
        }

        return result;
    }
};