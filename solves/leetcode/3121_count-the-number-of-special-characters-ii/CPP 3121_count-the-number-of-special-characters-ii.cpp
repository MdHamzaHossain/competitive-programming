class Solution
{
public:
    int numberOfSpecialChars(const string &word)
    {
        /**
         * 0 start
         * 1 lowercase found
         * 2 uppercase found
         *
         * if 0
         *  * upon finding lowercase, set to 1
         * if 1
         *  * upon finding uppercase, set to 2
         * if 2
         *  * upon finding lowercase, set to 3
         */
        vector<uint8_t> states(26, 0);

        for (auto &e : word)
        {
            if (e <= 'Z')
            {
                const int ind = e - 'A';
                if (states[ind] == 1)
                    states[ind] = 2;
                else if (states[ind] != 2)
                    states[ind] = 3;
            }
            else
            {

                const int ind = e - 'a';
                if (states[ind] == 0)
                    states[ind] = 1;
                else if (states[ind] == 2)
                    states[ind] = 3;
            }
        }
        int cnt = 0;
        for (auto &e : states)
        {
            cnt += e == 2;
        }

        return cnt;
    }
};