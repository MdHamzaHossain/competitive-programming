class Solution
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return dfs(root).first;
    }

    pair<TreeNode *, int> dfs(TreeNode *node)
    {
        if (!node)
            return {nullptr, 0};

        auto [lTree, lD] = dfs(node->left);
        auto [rTree, rD] = dfs(node->right);

        if (lD > rD)
            return {lTree, lD + 1};
        else if (lD < rD)
            return {rTree, rD + 1};
        else
            return {node, lD + 1};
    }
};