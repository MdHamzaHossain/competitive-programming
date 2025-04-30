class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int evens = 0;

        for (int num : nums)
            evens += to_string(num).size() % 2 == 0;

        return evens;
    }
};
