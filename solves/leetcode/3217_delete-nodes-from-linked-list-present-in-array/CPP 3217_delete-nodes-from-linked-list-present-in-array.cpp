/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        vector<bool> tr(100005, 0);
        for (auto e : nums)
        {
            tr[e] = true;
        }

        recur(head, tr);
        return head;
    }
    void recur(ListNode *&head, vector<bool> &tr)
    {
        if (head == nullptr || head->val == 0)
            return;
        if (tr[head->val])
        {
            head = head->next;

            recur(head, tr);
        }
        else
            recur(head->next, tr);
    }
};