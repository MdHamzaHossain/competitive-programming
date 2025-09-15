class Solution
{
public:
    int canBeTypedWords(const string &text, const string &brokenLetters)
    {
        bool isTypeable = true;                           // see if current word doesn't contain a broken letter/ is typeable
        int typeableWordCount = 0;                        // the amount of the typeable words
        for (auto i = text.begin(); i != text.end(); i++) // go character by character
        {
            if (*i == ' ') // alternate for each word
            {
                typeableWordCount += isTypeable; // increment if typeable
                isTypeable = true;               // new word stars with the flag set to true
            }
            else
            {
                if (brokenLetters.find(*i) != string::npos) // if a broken letter is found
                {
                    isTypeable = false;
                }
            }
        }
        typeableWordCount += isTypeable; // account for the last word
        return typeableWordCount;
    }
};