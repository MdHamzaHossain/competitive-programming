class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        int querI = 0;
        priority_queue<int> ava;
        priority_queue<int, vector<int>, greater<>> curr;

        ranges::sort(queries);

        for (int i = 0; i < nums.size(); ++i)
        {
            while (querI < queries.size() && queries[querI][0] <= i)
                ava.push(queries[querI++][1]);
            while (!curr.empty() && curr.top() < i)
                curr.pop();
            while (nums[i] > curr.size())
            {
                if (ava.empty() || ava.top() < i)
                    return -1;
                curr.push(ava.top()), ava.pop();
            }
        }

        return ava.size();
    }
};