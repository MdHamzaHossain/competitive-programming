/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *recur(const string &traversal, int d, int &i)
    {
        int n = 0;
        while (i + n < traversal.size() && traversal[i + n] == '-')
            n++;
        if (n != d)
            return nullptr;

        i += d;
        const int start = i;
        while (i < traversal.size() && isdigit(traversal[i]))
            i++;

        return new TreeNode(stoi(traversal.substr(start, i - start)),
                            recur(traversal, d + 1, i),
                            recur(traversal, d + 1, i));
    }
    TreeNode *recoverFromPreorder(string traversal)
    {
        int i = 0;
        return recur(traversal, 0, i);
    }
};