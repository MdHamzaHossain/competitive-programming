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
    TreeNode *recur(const vector<int> &pre, int startPre, int startEnd,
                    const vector<int> &post, int startPost, int endPost,
                    const unordered_map<int, int> &postInd)
    {
        if (startPre > startEnd)
            return nullptr;
        if (startPre == startEnd)
            return new TreeNode(pre[startPre]);

        const int rootVal = pre[startPre];
        const int lR = pre[startPre + 1];
        const int LRI = postInd.at(lR);
        const int Lsize = LRI - startPost + 1;

        TreeNode *root = new TreeNode(rootVal);
        root->left = recur(pre, startPre + 1, startPre + Lsize, post, startPost,
                           LRI, postInd);
        root->right = recur(pre, startPre + Lsize + 1, startEnd, post,
                            LRI + 1, endPost - 1, postInd);
        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        unordered_map<int, int> postInd;

        for (int i = 0; i < post.size(); ++i)
            postInd[post[i]] = i;

        return recur(pre, 0, pre.size() - 1, post, 0, post.size() - 1, postInd);
    }
};