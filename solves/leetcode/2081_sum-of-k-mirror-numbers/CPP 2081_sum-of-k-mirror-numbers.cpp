// TODO
class Solution
{
public:
    string toBase(long long number, int base)
    {
        string representation;
        while (number > 0)
        {
            int digit = number % base;
            representation = static_cast<char>(digit < 10 ? '0' + digit : 'A' + (digit - 10)) + representation;
            number /= base;
        }
        return representation.empty() ? "0" : representation;
    }

    bool isPalindrome(const string &s)
    {

        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
    long long kMirror(int base, int count)
    {
        long long sum = 0;

        for (int length = 1; count > 0; ++length)
        {

            int start = static_cast<int>(pow(10, (length - 1) / 2));
            int end = static_cast<int>(pow(10, (length + 1) / 2));

            for (int i = start; i < end; i++)
            {
                long long palindrome = i;

                for (int j = (length % 2 == 0) ? i : i / 10; j > 0; j /= 10)
                    palindrome = palindrome * 10 + j % 10;

                string baseRepresentation = toBase(palindrome, base);

                if (isPalindrome(baseRepresentation))
                {
                    sum += palindrome;
                    --count;
                    if (count == 0)
                        return sum;
                }
            }
        }
        return 0;
    };
};