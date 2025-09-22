//* FIRST
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int mosts = 0;
        // map<int,int> mp;
        vector<int> v(101, 0);
        int highestFreq = 0;
        for (auto e : nums)
        {
            v[e]++;
            // cout << "before e :" << e << " highestFreq: " << highestFreq << " mosts: " << mosts << endl;

            if (highestFreq == v[e])
            {
                mosts += highestFreq;
            }
            else if (highestFreq < v[e])
            {
                highestFreq = v[e];
                mosts = highestFreq;
            }
            // cout << "after e :" << e << " highestFreq: " << highestFreq << " mosts: " << mosts << endl;
        }
        return mosts;
    }
};
//* Pointer
class Solution
{
public:
    int maxFrequencyElements(const vector<int> &nums)
    {
        unsigned char a[102];

        unsigned char *h = &a[0];
        unsigned char *m = &a[101];
        unsigned char n = nums.size();
        while (n--)
        {
            a[nums[n]]++;
            const unsigned char c = a[nums[n]];
            const signed char d = (*h) - c;
            if (d == 0)
            {
                (*m) += (*h);
            }
            else if (d < 0)
            {
                (*h) = c;
                (*m) = (*h);
            }
        }
        return *m;
    }
};
// * Fastest
class Solution
{
public:
    int maxFrequencyElements(const vector<int> &nums)
    {
        unsigned char a[100];

        unsigned char h = 0;
        unsigned char m = 0;
        // unsigned char n = nums.size();
        for (unsigned char i = 0; i < nums.size(); i++)
        {
            const unsigned char c = ++a[nums[i] - 1];
            const signed char d = (h)-c;
            if (d == 0)
            {
                (m) += (h);
            }
            else if (d < 0)
            {
                (h) = c;
                (m) = (h);
            }
        }
        return m;
    }
};