// TODO
class Solution
{
public:
    int pairSum(ListNode *head)
    {

        vector<int> values;

        ListNode *current = head;
        while (current != nullptr)
        {
            values.push_back(current->val);
            current = current->next;
        }

        int maxTwinSum = 0;
        int n = values.size();

        for (int i = 0; i < n / 2; ++i)
        {
            int twinSum = values[i] + values[n - 1 - i];
            maxTwinSum = max(maxTwinSum, twinSum);
        }

        return maxTwinSum;
    }
};