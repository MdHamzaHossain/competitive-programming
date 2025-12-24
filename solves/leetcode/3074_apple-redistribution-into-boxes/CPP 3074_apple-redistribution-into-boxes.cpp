class Solution
{
public:
    int minimumBoxes(const vector<int> &apple, vector<int> &capacity)
    {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int i = 0;

        for (i; i < capacity.size(); i++)
        {
            if (sum < 1)
                break;
            sum -= capacity[i];
        }
        return i;
    }
};