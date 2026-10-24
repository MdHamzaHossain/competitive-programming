class Solution
{
private:
    int getDay(string s)
    {
        const int days[] = {
            0,
            0,
            31,
            59,
            90,
            120,
            151,
            181,
            212,
            243,
            273,
            304,
            334,
            365};

        return days[((s[0] - '0') * 10 + (s[1] - '0'))] + (s[3] - '0') * 10 + (s[4] - '0');
    }

public:
    int countDaysTogether(const string arriveAlice, const string leaveAlice, const string arriveBob, const string leaveBob)
    {
        const int a2 = getDay(leaveAlice), b2 = getDay(leaveBob), a1 = getDay(arriveAlice), b1 = getDay(arriveBob);
        // cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
        if (b1 > a2 || a1 > b2)
            return 0;
        return max(min(a2, b2) - max(a1, b1), 0) + 1;
    }
};