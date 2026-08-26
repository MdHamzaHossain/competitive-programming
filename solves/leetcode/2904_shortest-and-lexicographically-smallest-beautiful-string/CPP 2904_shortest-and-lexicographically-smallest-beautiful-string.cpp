// TODO
class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int stringLength = s.size();
        string result = "";

        for (int startPos = 0; startPos < stringLength; ++startPos)
        {

            for (int endPos = startPos + k; endPos <= stringLength; ++endPos)
            {

                string currentSubstring = s.substr(startPos, endPos - startPos);

                int onesCount = count(currentSubstring.begin(), currentSubstring.end(), '1');

                if (onesCount == k)
                {

                    if (result == "" ||
                        endPos - startPos < result.size() ||
                        (endPos - startPos == result.size() && currentSubstring < result))
                    {
                        result = currentSubstring;
                    }
                }
            }
        }

        return result;
    }
};
