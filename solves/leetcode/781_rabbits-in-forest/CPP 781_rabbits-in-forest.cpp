class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        map<int, int> mapper;
        for (int answer : answers)
            mapper[answer]++;

        int cnt = 0;
        for (auto &[k, v] : mapper)
            cnt += (int)ceil((double)v / (k + 1)) * (k + 1);

        return cnt;
    }
};
