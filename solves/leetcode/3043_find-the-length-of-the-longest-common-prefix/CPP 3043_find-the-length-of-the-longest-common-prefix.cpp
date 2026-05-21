// TODO
class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {

        unordered_set<int> prefixSet;

        for (int num : arr1)
        {
            while (num > 0)
            {
                prefixSet.insert(num);
                num /= 10;
            }
        }

        int maxPrefixLength = 0;

        for (int num : arr2)
        {

            while (num > 0)
            {

                if (prefixSet.count(num))
                {

                    int currentPrefixLength = static_cast<int>(log10(num)) + 1;
                    maxPrefixLength = max(maxPrefixLength, currentPrefixLength);
                    break;
                }
                num /= 10;
            }
        }

        return maxPrefixLength;
    }
};