class Solution
{
public:
    int minimumOperations(const vector<int> &nums)
    {
        unsigned char cnt = 0;
        for (auto &e : nums)
            cnt += (e % 3 == 0) ? 0 : 1;
        return cnt;
    }
};